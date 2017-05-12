//---------------------------------fractional calculation-------------------------------------------------
#define int64 long long
#define maxN 55

char buffer[maxN];

int64 gcd(int64 a, int64 b)
{
    return b ? gcd(b, a % b) : a;
}

struct Fraction
{
    int64 a, b;
    Fraction()
    {
        a = 0;
        b = 1;
    }
    Fraction(int64 _a, int64 _b)
    {
        a = _a;
        b = _b;
        make();
    }

    Fraction operator + (const Fraction &f) const
    {
        int64 ra = a * f.b + f.a * b;
        int64 rb = b * f.b;
        return Fraction(ra, rb);
    }

    Fraction operator - (const Fraction &f) const
    {
        int64 ra = a * f.b - f.a * b;
        int64 rb = b * f.b;
        return Fraction(ra, rb);
    }

    Fraction operator * (const Fraction &f) const
    {
        int64 ra = a * f.a;
        int64 rb = b * f.b;
        return Fraction(ra, rb);
    }

    Fraction operator / (const Fraction &f) const
    {
        int64 ra = a * f.b;
        int64 rb = b * f.a;
        return Fraction(ra, rb);
    }

    bool operator == (const Fraction &f) const
    {
        return a * f.b == f.a * b;
    }

    bool operator < (const Fraction &f) const
    {
        return a * f.b < f.a * b;
    }

    Fraction getAbs()
    {
        return Fraction(abs(a), abs(b));
    }

    void print()
    {
        if (a == 0) printf("0");

        else if (b == 1) printf("%lld", a);

        else printf("%lld/%lld", a, b);
    }
    void read()
    {
        scanf("%s", buffer);
        //   puts("NNNN");
        bool exist = false;

        for (int i = 0; buffer[i] && !exist; i++)
            if (buffer[i] == '/')
                exist = true;

        if (exist)
            sscanf(buffer, " %lld/%lld ", &a, &b);
        else
        {
            sscanf(buffer, " %lld ", &a);
            b = 1;
        }
        make();
    }
    void make()
    {
        int64 g = gcd(a, b);
        a /= g;
        b /= g;
        if (a == 0) b = 1;
        if (b < 0) a = -a, b = -b;
    }
};

//---------------------------------------------xxxxxxxxxxxxxxxx---------------------------------------

