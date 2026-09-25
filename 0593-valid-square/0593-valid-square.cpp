class Solution
{
private:
    int distance(vector<int> &p1, vector<int> &p2)
    {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];

        return (x * x) + (y * y);
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2,
                     vector<int> &p3, vector<int> &p4)
    {
        vector<int> distances;

        distances.push_back(distance(p1, p2));
        distances.push_back(distance(p1, p3));
        distances.push_back(distance(p1, p4));
        distances.push_back(distance(p2, p3));
        distances.push_back(distance(p2, p4));
        distances.push_back(distance(p3, p4));

        sort(distances.begin(), distances.end());

        return distances[0] > 0 &&
               distances[0] == distances[1] &&
               distances[1] == distances[2] &&
               distances[2] == distances[3] &&
               distances[4] == distances[5];
    }
};