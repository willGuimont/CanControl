#!/usr/bin/env bash
set -euo pipefail

# Directories to format
DIRS=(src include test examples)

# File extensions to format
EXTS=("*.c" "*.cpp" "*.cc" "*.cxx" "*.h" "*.hpp" "*.hh" "*.hxx")

if ! command -v clang-format >/dev/null 2>&1; then
    echo "Error: clang-format not found in PATH. Please install it first." >&2
    exit 1
fi

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

for dir in "${DIRS[@]}"; do
    TARGET_DIR="${ROOT_DIR}/${dir}"
    if [ ! -d "${TARGET_DIR}" ]; then
        continue
    fi
    for ext in "${EXTS[@]}"; do
        # Use find + xargs to handle many files efficiently
        find "${TARGET_DIR}" -type f -name "${ext}" -print0 | xargs -0 -r clang-format -i
    done
done

echo "Code formatted with clang-format using .clang-format configuration."
