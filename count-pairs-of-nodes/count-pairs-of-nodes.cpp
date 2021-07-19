////Please open this solution in VS2019
//https://leetcode.com/problems/count-pairs-of-nodes/
//2021 07 19 to 2021 mm dd

//STATUS: TIME LIMIT EXCEEDED

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


// 2021 07 19 S3 TIME LIMIT EXCEEDED

class Solution {
private:
    std::set<int> uniques;
    int* pIncidentArray;

    void uniques_init(vector<vector<int>>& edges)
    {
        for (vector<int>& pair : edges)
        {
            for (int& value : pair)
            {
                uniques.insert(value);
            }
        }
    }

    void pIncidentArray_init(int n) {
        pIncidentArray = new int[n * n];
        for (int i = 0; i < n * n; i++) {
            pIncidentArray[i] = 0;
        }
    }

    //usage: caller gives actual numbers of uv-pair, function will convert to array coords
    int pIncidentArray_get(int n, int u, int v) {
        u--;
        v--;
        return *(pIncidentArray + u * n + v);
    }

    //usage: caller gives actual numbers of uv-pair, function will convert to array coords
    void pIncidentArray_set(int n, int u, int v, int val) {
        u--;
        v--;
        *(pIncidentArray + u * n + v) = val;
    }

    //usage: caller gives actual numbers of uv-pair, function will convert to array coords
    void pIncidentArray_increment(int n, int u, int v) {
        u--;
        v--;
        *(pIncidentArray + u * n + v) += 1;
    }

        //usage: caller gives actual numbers of uv-pair, function will convert to array coords
    void pIncidentArray_decrement(int n, int u, int v) {
        u--;
        v--;
        *(pIncidentArray + u * n + v) -= 1;
    }

    void pIncidentArray_print(int n) {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                std::cout << pIncidentArray_get(n, i, j) << ";\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void pIncidentArray_destroy() {
        delete [] pIncidentArray;
        pIncidentArray = nullptr;
    }
public:
    Solution() :pIncidentArray(nullptr) {}

    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        //find out unique values from edges
        uniques_init(edges);

        //init incidentarray
        pIncidentArray_init(n);

        for (vector<int>& pair : edges)
        {
            for(int t : pair)
            {
                for (int u = 1; u < t; u++)
                {
                    pIncidentArray_increment(n, u, t);
                }
                for (int v = t + 1; v <= n; v++)
                {
                    pIncidentArray_increment(n, t, v);
                }
                                                    //DEBUG
                pIncidentArray_print(n);
            }
        }

        //for each edge, -1 incident because the same pair triggers twice in the above step
        //we must also make sure to swap a and b if a > b
        //as the problem defines the condition a < b (see URL)
        for (vector<int>& pair : edges)
        {
            if (pair[0] < pair[1])
            {
                pIncidentArray_decrement(n, pair[0], pair[1]);
            }
            else
            {
                pIncidentArray_decrement(n, pair[1], pair[0]);
            }
        }
                        //DEBUG
        pIncidentArray_print(n);

        //create output vector and init all to 0
        vector<int> output(queries.size(), 0);

        //gather up output per query
        for (int u = 1; u < n; u++)
        {
            for (int v = u + 1; v <= n; v++)
            {
                for (int i = 0; i < queries.size(); i++)
                {
                    if (pIncidentArray_get(n, u, v) > queries[i])
                    {
                        output[i]++;
                    }
                }
            }
        }

        //destroy incidentarray
        pIncidentArray_destroy();

        return output;
    }
};

int main()
{
    //int n = 4;
    //vector<vector<int>> edges = { {1,2},{2,4},{1,3},{2,3},{2,1} };
    //vector<int> queries = { 2,3 };

    int n = 5;
    vector<vector<int>> edges = { {4,5},{1,3},{1,4} };
    vector<int> queries = { 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 2 };

    Solution sln;
    vector<int> output = sln.countPairs(n, edges, queries);
    for (int o : output)
    {
        std::cout << o << "; ";
    }
    std::cout << std::endl;


    return 0;
}