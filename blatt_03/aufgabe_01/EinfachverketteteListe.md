# EinfachverketteteListe

## Data-Klasse

| Data  |
|-------|
| + Data(const char* pData) |
|-----------------------------------|
| - string data |
|-----------------------------------|
| + Data(const char* pData) |
| + string GetData() |
| + void PrintData() |

## List-Klasse

| List |
|-------|
| - List() |
| - ~List() |
|-------|
| - List *pNextList |
| - Data *pData |
|-------|
| + static List& CreateList() |
| + static void DeleteList(List& list) |
| + bool AddToList(Data *pD) |
| + void PrintList() const |

- Pop_back: delete the last element of the queue - Push_front: add a new elememt to the front of the queue - pop_front: delete the first element of the queue - Insert: insert a new element on a specific position - Erase: erase a specific element - Assign: assign a value to an existing element 