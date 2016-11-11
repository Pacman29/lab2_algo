#include "levenshtein_algorithm.h"
#include <QGenericMatrix>
template <class T>
int levenshtein_distance(T src, T dst)
{
    const int m = src.size();
    const int n = dst.size();
    if (!m)
        return n;
    if (!n)
        return m;
    QGenericMatrix<n+1,m+1,int> matrix;

    for(int i = 0; i<=m || i<=n; ++i)
    {
        if(i<=m)
             matrix[i][0] = i;
        if(i<=n)
            matrix[0][i] = i;
    }

    int above_cell,
                          left_cell,
                          diagonal_cell,
                          cost;

    for (int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cost = src[i - 1] != dst[j - 1];
            above_cell = matrix[i - 1][j];
            left_cell = matrix[i][j - 1];
            diagonal_cell = matrix[i - 1][j - 1];
            matrix[i][j] = std::min(std::min(above_cell + 1, left_cell + 1), diagonal_cell + cost);
        }
    return matrix[m][n];
}

template <class T>
int damerau_levenshtein_distance(T src, T dst)
{

    if(src.size() > dst.size())
        std::swap(src,dst);
    int m = src.size();  //m - first
    int max, n = max = dst.size();  //n-second

    if (!m)
        return n;
    if (!n)
        return m;

    QVector<int> currentRow(m + 1);
    QVector<int> previousRow(m + 1);
    QVector<int> transpositionRow(m + 1);

    for (int i = 0; i <= m; i++)
        previousRow[i] = i;

    char lastSecondCh = 0;
    for (int i = 1; i <= m; i++)
    {
        int secondCh = dst[i - 1];
        currentRow[0] = i;

        // Вычисляем только диагональную полосу шириной 2 * (max + 1)
        int from = std::max(i - max - 1, 1);
        int to = std::min(i + max + 1, n);

        int lastFirstCh = 0;
        for (int j = from; j <= to; j++)
        {
            int firstCh = src[j - 1];

            // Вычисляем минимальную цену перехода в текущее состояние из предыдущих среди удаления, вставки и
            // замены соответственно.
            int cost = firstCh != secondCh;
            int value = std::min(std::min(currentRow[j - 1] + 1, previousRow[j] + 1), previousRow[j - 1] + cost);

            // Если вдруг была транспозиция, надо также учесть и её стоимость.
            if (firstCh == lastSecondCh && secondCh == lastFirstCh)
                value = std::min(value, transpositionRow[j - 2] + cost);

            currentRow[j] = value;
            lastFirstCh = firstCh;
        }
        lastSecondCh = secondCh;

        QVector<int> tempRow = transpositionRow;
        transpositionRow = previousRow;
        previousRow = currentRow;
        currentRow = tempRow;
    }
    return previousRow[n];
}

