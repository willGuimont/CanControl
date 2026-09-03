#if defined(CANCONTROL_MAIN)

#if defined(EXAMPLE_QUEUE)
#include "../examples/main_queue.cpp"
#endif

#if defined(EXAMPLE_BASIC)
#include "../examples/main.cpp"
#endif

#elif !defined(ARDUINO) && !defined(UNIT_TEST)

int main()
{
    return 0;
}

#endif
