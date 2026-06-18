#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Cell {
    int r, c;
};

void replaceRec(int **data, int h, int w, int r, int c, int bc, int fc)
{
    if (r < 0 || r >= h || c < 0 || c >= w)
        return;

    if (data[r][c] != bc)
        return;

    data[r][c] = fc;

    replaceRec(data, h, w, r+1, c, bc, fc);
    replaceRec(data, h, w, r-1, c, bc, fc);
    replaceRec(data, h, w, r, c+1, bc, fc);
    replaceRec(data, h, w, r, c-1, bc, fc);
}

void replaceQueue(int **data, int h, int w, int sr, int sc, int bc, int fc)
{
    queue<Cell> q;
    q.push({sr, sc});

    while(!q.empty())
    {
        Cell cur = q.front();
        q.pop();

        int r = cur.r;
        int c = cur.c;

        if (r < 0 || r >= h || c < 0 || c >= w)
            continue;

        if (data[r][c] != bc)
            continue;

        data[r][c] = fc;

        q.push({r+1, c});
        q.push({r-1, c});
        q.push({r, c+1});
        q.push({r, c-1});
    }
}

void replaceStack(int **data, int h, int w, int sr, int sc, int bc, int fc)
{
    stack<Cell> st;
    st.push({sr, sc});

    while(!st.empty())
    {
        Cell cur = st.top();
        st.pop();

        int r = cur.r;
        int c = cur.c;

        if (r < 0 || r >= h || c < 0 || c >= w)
            continue;

        if (data[r][c] != bc)
            continue;

        data[r][c] = fc;

        st.push({r+1, c});
        st.push({r-1, c});
        st.push({r, c+1});
        st.push({r, c-1});
    }
}

void print(int **data, int h, int w)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int h = 5, w = 5;

    int **data = new int*[h];
    for(int i = 0; i < h; i++)
        data[i] = new int[w];

    int temp[5][5] = {
        {1,1,2,2,2},
        {1,2,2,2,3},
        {1,1,2,3,3},
        {4,2,2,2,3},
        {4,4,4,2,2}
    };

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            data[i][j] = temp[i][j];

    cout << "Before:\n";
    print(data, h, w);

    int sr = 1, sc = 2;
    int bc = data[sr][sc];
    int fc = 9;

    replaceRec(data, h, w, sr, sc, bc, fc);

    cout << "After:\n";
    print(data, h, w);

    return 0;
}