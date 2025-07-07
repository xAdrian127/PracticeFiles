#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    float g, h;
    Node* parent;
    /**
     * @brief Node constructor with member initializer list.
     * 
     * The colon (:) after the constructor signature introduces the member initializer list,
     * which initializes member variables (x, y, g, h, parent) directly before the constructor body executes.
     * This is more efficient and sometimes necessary (e.g., for const or reference members).
     * 
     * @param x The x-coordinate of the node.
     * @param y The y-coordinate of the node.
     * @param g The cost from the start node to this node (default is 0).
     * @param h The heuristic cost estimate from this node to the goal (default is 0).
     * @param parent Pointer to the parent node in the path (default is nullptr).
     **/
    Node(int x, int y, float g = 0, float h = 0, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}
    float f() const { return g + h; }

    /**
     * @brief Equality operator for Node.
     * 
     * Checks if two nodes have the same x and y coordinates.
     * This is used for comparing nodes in sets and other containers.
     * 
     * @param other The node to compare with.
     * @return true if both nodes have the same coordinates, false otherwise.
     **/
    bool operator==(const Node& other) const { return x == other.x && y == other.y; }
};

struct NodeHasher {
    size_t operator()(const Node* n) const {
        return hash<int>()(n->x) ^ hash<int>()(n->y);
    }
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->f() > b->f();
    }
};

float heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, const vector<vector<int>>& grid) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0;
}

vector<Node*> getNeighbors(Node* node, const vector<vector<int>>& grid) {
    vector<Node*> neighbors;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        int nx = node->x + dx[i], ny = node->y + dy[i];
        if (isValid(nx, ny, grid)) {
            neighbors.push_back(new Node(nx, ny));
        }
    }
    return neighbors;
}

vector<Node> reconstructPath(Node* end) {
    vector<Node> path;
    for (Node* n = end; n; n = n->parent)
        path.push_back(*n);
    reverse(path.begin(), path.end());
    return path;
}

vector<Node> astar(const vector<vector<int>>& grid, int sx, int sy, int ex, int ey) {
    priority_queue<Node*, vector<Node*>, CompareNode> open;
    unordered_set<Node*, NodeHasher> closed;
    Node* start = new Node(sx, sy, 0, heuristic(sx, sy, ex, ey));
    open.push(start);

    while (!open.empty()) {
        Node* current = open.top(); open.pop();
        if (current->x == ex && current->y == ey)
            return reconstructPath(current);

        closed.insert(current);

        for (Node* neighbor : getNeighbors(current, grid)) {
            neighbor->g = current->g + 1;
            neighbor->h = heuristic(neighbor->x, neighbor->y, ex, ey);
            neighbor->parent = current;

            bool inClosed = false;
            for (auto n : closed)
                if (*n == *neighbor) { inClosed = true; break; }
            if (inClosed) { delete neighbor; continue; }

            open.push(neighbor);
        }
    }
    return {};
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    int sx = 0, sy = 0, ex = 4, ey = 4;
    auto path = astar(grid, sx, sy, ex, ey);
    if (!path.empty()) {
        cout << "Path:\n";
        for (auto& n : path)
            cout << "(" << n.x << "," << n.y << ") ";
        cout << endl;
    } else {
        cout << "No path found.\n";
    }
    return 0;
}