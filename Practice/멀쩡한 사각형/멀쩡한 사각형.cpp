//https://school.programmers.co.kr/learn/courses/30/lessons/62048

long long GCD(long long left, long long right)
{
    long long Mod = left % right;
    if (Mod == 0)
    {
        return right;
    }
    return GCD(right, Mod);
}

long long solution(int w, int h)
{
    long long GCDValue = 1;

    if (w < h)
    {
        GCDValue = GCD(w, h);
    }
    else
    {
        GCDValue = GCD(h, w);
    }

    long long ComprimeRectH = h / GCDValue;
    long long ComprimeRectW = w / GCDValue;

    long long EraseRect = ComprimeRectH + ComprimeRectW - 1;
    long long Ratio = h / ComprimeRectH;
    long long FullSize = static_cast<long long>(h) * static_cast<long long>(w);

    long long answer = FullSize - (Ratio * EraseRect);
    return answer;
}