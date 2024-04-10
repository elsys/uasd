// https://leetcode.com/problems/keys-and-rooms/description/

void visitRoom(int **rooms, int *visited, int current, int *roomsColSize)
{
    if (visited[current])
    {
        return;
    }

    visited[current] = 1;

    for (int i = 0; i < roomsColSize[current]; i++)
    {
        visitRoom(rooms, visited, rooms[current][i], roomsColSize);
    }
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    int *visited = (int *)calloc(roomsSize, sizeof(int));
    visitRoom(rooms, visited, 0, roomsColSize);

    for (int i = 0; i < roomsSize; i++)
    {
        if (visited[i] == 0)
        {
            return false;
        }
    }

    return true;
}