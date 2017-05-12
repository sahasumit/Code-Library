
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


//-----------------------***********gauss elemenation************----------------------------
int n,m;// m is number of equation and n is number of unknown variables
Fraction a[maxN][maxN],res[maxN];
const Fraction ZERO = Fraction(0, 1);
const Fraction ONE = Fraction(1, 1);
void printing()
{
    puts("STARTING");
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            a[i][j].print();
            cout<<" ";
        }

        puts("");
    }
    puts("ENDING");
}

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
void solve()
{
//m is number of equation and n is number of unknown variables

    for (int i = 1, j = 1; i <= m && j <= n; )
    {
        // find pivot in column j, starting at row i
        int maxi = i;
        fr(u, i + 1, m) if (a[maxi][j].getAbs() < a[u][j].getAbs())
            maxi = u;
        if (!(a[maxi][j] == ZERO))
        {
            // swap row i and row maxi
            fr(v, 1, n + 1) swap(a[i][v], a[maxi][v]);


            // loop through each row below
            fr(u, 1, m)
            if (u != i)   // row u
            {
                fr(v, j+1 , n + 1)
                {
                    a[u][v] = a[u][v] - a[i][v] * (a[u][j] / a[i][j]);
                }
                a[u][j] = ZERO;
            }
//            printing();
            i++;
        }
        j++;
    }
//    printing();
    int cnt = 0;
    fr(i, 1, m)
    {
        bool zero = true;
        fr(j, 1, n) if (!(a[i][j] == ZERO))
        {
            zero = false;
            break;
        }
        if (zero && !(a[i][n + 1] == ZERO))
        {
            cnt = -1;
            break;
        }
    }
    if (cnt >= 0)
    {
        for (int i = 1, j = 1; i <= m & j <= n; )
        {
            if (!(a[i][j] == ZERO))
            {
                res[j] = a[i][n + 1] / a[i][j];
                cnt++;
                i++;
            }
            j++;
        }
    }
    if (cnt == -1)
        puts("No Solution.");

    else if (cnt < n)
        printf("Infinitely many solutions containing %d arbitrary constants.\n", n - cnt);
    else
    {
        fr(i, 1, n)
        {
            printf("x[%d] = ", i);
            res[i].print();
            puts("");
        }
    }
}
//-------------------------------------*******************-------------------------

