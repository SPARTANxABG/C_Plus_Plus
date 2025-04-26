#include <iostream>
#include <queue>

using namespace std;

bool findPath(int adjMatrix[11][11], int s, int e)
{
    if (s == e && adjMatrix[s][e] == 1)
        return true;

    else if (s == e && adjMatrix[s][e] == 0)
        return false;

    bool visited[11];

    for (int i = 0; i < 11; i++)
        visited[i] = false;

    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int c = q.front();
        q.pop();

        for (int i = 0; i < 11; i++)
        {
            if (i == e && adjMatrix[c][i] == 1)
                return true;

            if (visited[i] == 0 && adjMatrix[c][i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}


int main()
{
    int adjMatrix[11][11] = { {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0} };

    char start, end, choice;

    while (1)
    {
        cout << "Valid vertices are A thru K";
        cout << "\nEnter a starting vertice: ";
        cin >> start;
        cout << "Enter an ending vertice: ";
        cin >> end;

        bool pathExists = findPath(adjMatrix, start - 65, end - 65);

        if (pathExists == 1)
            cout << endl << "Path from " << start << " to " << end << " found!" << endl;
        else
            cout << endl << "Path from " << start << " to " << end << " not found!" << endl;

        cout << endl << "Check another path? (Y/N) ";
        cin >> choice;
        if (choice == 'N')
            exit(0);
    }

    return 0;
}