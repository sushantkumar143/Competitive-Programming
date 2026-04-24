bool lockNode(int x, int uid) {
    vector<int> path = getPath(x);

    if (lb[x] != 0) return false;
    lb[x] = -1; 

    if (ldc[x] > 0) {
        lb[x] = 0;
        return false;
    }

    for (int i = 0; i < (int)path.size() - 1; i++) {
        if (lb[path[i]] != 0) {
            lb[x] = 0;
            return false;
        }
    }

    lb[x] = uid;

    for (int i = 0; i < (int)path.size() - 1; i++) {
        ldc[path[i]]++;
    }

    return true;
}



bool lockNode(int x, int uid) {
    vector<int> path = getPath(x);

    for (int i = 0; i < (int)path.size() - 1; i++) {
        ldc[path[i]]++;
    }

    if (lb[x] != 0 || ldc[x] > 0) {
        for (int i = 0; i < (int)path.size() - 1; i++)
            ldc[path[i]]--;
        return false;
    }

    for (int i = 0; i < (int)path.size() - 1; i++) {
        if (lb[path[i]] != 0) {
            for (int j = 0; j < (int)path.size() - 1; j++)
                ldc[path[j]]--;
            return false;
        }
    }

    lb[x] = uid;

    return true;
}




bool lockNode(int x, int uid) {
    vector<int> path = getPath(x);

    if (lb[x] != 0 || ldc[x] > 0)
        return false;

    for (int i = 0; i < (int)path.size() - 1; i++) {
        if (lb[path[i]] != 0)
            return false;
    }

    if (lb[x] != 0) return false;
    lb[x] = -1;

    if (ldc[x] > 0) {
        lb[x] = 0;
        return false;
    }

    for (int i = 0; i < (int)path.size() - 1; i++) {
        if (lb[path[i]] != 0) {
            lb[x] = 0;
            return false;
        }
    }

    lb[x] = uid;

    for (int i = 0; i < (int)path.size() - 1; i++) {
        ldc[path[i]]++;
    }

    return true;
}