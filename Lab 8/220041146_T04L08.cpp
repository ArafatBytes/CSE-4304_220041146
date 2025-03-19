#include <bits/stdc++.h>
using namespace std;

string format(double value)
{
    stringstream stream;
    stream << fixed << setprecision(2) << value;
    return stream.str();
}

int main()
{
    map<string, set<pair<int, int>>> lines;
    int numPoints;
    cin >> numPoints;

    vector<pair<int, int>> points(numPoints);
    for (int i = 0; i < numPoints; ++i)
    {
        cin >> points[i].first >> points[i].second;
    }

    for (int a = 0; a < numPoints - 1; ++a)
    {
        for (int b = a + 1; b < numPoints; ++b)
        {
            string equation;
            double slope, intercept;

            auto [x1, y1] = points[a];
            auto [x2, y2] = points[b];

            if (x1 == x2)
            {
                equation = "x = " + format(x1);
            }
            else
            {
                slope = (y2 - y1) / (x2 - x1);
                intercept = y1 - slope * x1;

                equation = "y = " + format(slope) + "x ";
                equation += (intercept < 0 ? "- " : "+ ") + format(fabs(intercept));
            }

            lines[equation].insert(points[a]);
            lines[equation].insert(points[b]);
        }
    }

    int maxPoints = 0;
    string dominantLine;

    for (const auto &[equation, pointSet] : lines)
    {
        if (pointSet.size() > maxPoints)
        {
            maxPoints = pointSet.size();
            dominantLine = equation;
        }
    }

    cout << dominantLine << endl;
    cout << maxPoints << endl;

    return 0;
}
