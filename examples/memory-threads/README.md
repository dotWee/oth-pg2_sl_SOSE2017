# memory-threads

Einfaches Beispiel, um die Notwendigkeit eines Lock-Mechanismus bei Threads zu demonstrieren.

## Ausführung

```bash
make all

g++ main-unlocked.cpp -o MainUnlocked.o -std=c++0x -pthread
chmod +x MainUnlocked.o
./MainUnlocked.o
END-UNLOCKED of main value = 7021

g++ main-lock_guard.cpp -o MainLocked.o -std=c++0x -pthread
chmod +x MainLocked.o
./MainLocked.o
END-LOCK_GUARD of main value = 0
rm -rf MainLocked.o
rm -rf MainUnlocked.o
```