//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

struct MinMax
{
    int min, int max;
};

struct MinMax
minmax_min_comparison(int *a, int n)
{
    int _min, _max, __max, __min;
    if (a[0] > a[1])
    {
        _max = a[0];
        _min = a[1];
    }
    else
    {
        _max = a[1];
        _min = a[0];
    }
    for (int i = 2; i < n - ; i += 2)
    {
        if (a[i] < a[i + 1])
        {
            __max = a[i + 1];
            __min = a[i];
        }
        else
        {
            __max = a[i];
            __min = a[i + 1];
        }
        if (__max > _max)
            _max = __max;
        if (__min < _min)
            _min = __min;
    }

    struct MinMax ans;
    ans.min = _min;
    ans.max = _max;
    return ans;
}