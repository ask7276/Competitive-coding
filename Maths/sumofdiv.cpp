ll sigma(ll num)
{
    ll count = 0;
    ll pp = 1;
    while (num % 2 == 0)
    {
        count++;
        num /= 2;
    }
    pp *= (pow(2, (count + 1)) - 1);
    for (ll i = 3; i <= sqrt(num); i += 2)
    {
        count = 0;
        while (num % i == 0)
        {
            count++;
            num /= i;
        }
        pp *= (pow(i, (count + 1)) - 1) / (i - 1);
    }
    if (num > 2)
    {
        pp *= (num + 1);
    }
    return pp;
}
