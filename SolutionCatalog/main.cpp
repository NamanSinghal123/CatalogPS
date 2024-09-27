#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double lagrangeInterpolation(vector<pair<int, int>>& points) {
    double c = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        double term = points[i].second;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (0 - points[j].first) / (double)(points[i].first - points[j].first);
            }
        }
        c += term;
    }

    return c;
}

int main() {
    vector<pair<int, int>> points = {
        {1, 4},
        {2, 7},
        {3, 12},
        {6, 39}
    };


     vector<pair<int, long long>> points2 = {
        {1, 28735619723837LL},
        {2, 28735619723850LL},
        {3, 22876796448699115LL},
        {4, 9925932580766147LL},
        {5, 28735619723873LL},
        {6, 28735619654702LL}
    };

    vector<pair<int, int>> selectedPoints = {points[0], points[1], points[2]};
    vector<pair<int, int>> selectedPoints2 = {points2[0], points2[1], points2[2],points2[3],points2[4],points2[5]};
    double result = lagrangeInterpolation(selectedPoints);
    double result2 = lagrangeInterpolation(selectedPoints2);
    cout << "The constant term c is: " << result << endl;
    cout << "The constant term c is: " << result2 << endl;

    return 0;
}
