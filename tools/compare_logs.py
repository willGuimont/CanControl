import argparse
import csv
import statistics
from collections import defaultdict


def load_log(filename):
    """
    Loads a CAN log CSV.
    Returns a dict: { can_id: [timestamps] }
    """
    data = defaultdict(list)
    try:
        with open(filename, "r") as f:
            reader = csv.DictReader(f)
            for row in reader:
                try:
                    ts = float(row["Timestamp"])
                    can_id = row["CAN_ID"]
                    data[can_id].append(ts)
                except (ValueError, KeyError):
                    continue
    except FileNotFoundError:
        print(f"Error: File {filename} not found.")
        return None
    return data


def analyze_capture(name, data):
    print(f"\n--- Analysis: {name} ---")
    print(f"Total Unique IDs: {len(data)}")

    stats = {}

    for can_id, timestamps in data.items():
        count = len(timestamps)
        if count < 2:
            period_avg = 0
            period_std = 0
        else:
            diffs = [timestamps[i] - timestamps[i - 1] for i in range(1, count)]
            period_avg = statistics.mean(diffs)
            period_std = statistics.stdev(diffs) if count > 2 else 0

        stats[can_id] = {
            "count": count,
            "period_avg": period_avg,
            "period_std": period_std,
        }

        print(
            f"ID: {can_id:<10} Count: {count:<5} Avg Period: {period_avg*1000:<6.2f} ms (+/- {period_std*1000:<5.2f} ms)"
        )

    return stats


def compare(file1, file2):
    print(f"Comparing {file1} vs {file2}...")

    data1 = load_log(file1)
    data2 = load_log(file2)

    if data1 is None or data2 is None:
        return

    stats1 = analyze_capture(file1, data1)
    stats2 = analyze_capture(file2, data2)

    all_ids = set(data1.keys()) | set(data2.keys())

    print("\n--- Comparison Summary ---")
    print(f"CAN ID\t{file1} (ms)\t{file2} (ms)\tDiff (%)")
    print("-" * 60)

    for can_id in sorted(all_ids):
        s1 = stats1.get(can_id)
        s2 = stats2.get(can_id)

        p1 = f"{s1['period_avg']*1000:.2f}" if s1 and s1["count"] > 1 else "N/A"
        p2 = f"{s2['period_avg']*1000:.2f}" if s2 and s2["count"] > 1 else "N/A"

        diff_str = ""
        if s1 and s2 and s1["count"] > 1 and s2["count"] > 1:
            d = s2["period_avg"] - s1["period_avg"]
            pct = (d / s1["period_avg"]) * 100
            diff_str = f"{pct:+.1f}%"
        elif s1 and not s2:
            diff_str = "MISSING in File 2"
        elif not s1 and s2:
            diff_str = "NEW in File 2"

        print(f"{can_id}\t{p1}\t{p2}\t{diff_str}")


def main():
    parser = argparse.ArgumentParser(description="Compare two CAN log CSVs")
    parser.add_argument("file1", help="First CSV file (e.g. no_client.csv)")
    parser.add_argument("file2", help="Second CSV file (e.g. with_client.csv)")

    args = parser.parse_args()

    compare(args.file1, args.file2)


if __name__ == "__main__":
    main()
