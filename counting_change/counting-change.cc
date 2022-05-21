constexpr long long help_function(int position, const long long amount)
{
    int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    if (amount == 0)
        return 1;
    if (amount < 0)
        return 0;
    else
    {
        if (position == 0)
            return help_function(position, amount - coins[position]);
        else
            return help_function(position, amount - coins[position])
                + help_function(position - 1, amount);
    }
}

constexpr long long count_change(const long long amount)
{
    return help_function(7, amount);
}
