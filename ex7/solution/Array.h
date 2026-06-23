/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T>
class Array {
private:
    int size; // גודל המערך
    T* elements; // מצביע לאיבר הראשון במערך

public:
    // בנאים והורסים
    Array(); // בנאי ברירת מחדל
    ~Array(); // Destructor לניקוי זיכרון דינמי

    // מתודות
    void Add(T element); // הוספת איבר בסוף המערך
    T remove(int index); // מחיקת איבר לפי אינדקס והחזרת הערך שנמחק[cite: 1]
    int getSize() const; // החזרת גודל המערך[cite: 1]

    // אופרטורים[cite: 1]
    T& operator[](int index);
    const T& operator[](int index) const;

    // הצהרה על אופרטור הדפסה (ב-Templates מקובל להצהיר כידיד או לממש בפנים)[cite: 1]
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
};

#endif // ARRAY_H