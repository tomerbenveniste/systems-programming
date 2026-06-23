/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
*/
#include <iostream>
#include <stdexcept>
#include "Array.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"

using namespace std;

int main() {
    // יצירת מערך של מצביעים ל-Shape[cite: 1]
    Array<Shape*> shapesArray;
    int choice = 0;

    while (choice != 4) {
        // הצגת תפריט[cite: 1]
        cout << "\nMenu:\n";
        cout << "(1) Add a new shape\n"; // הוספת צורה[cite: 1]
        cout << "(2) Delete a shape by index\n"; // מחיקת צורה לפי אינדקס[cite: 1]
        cout << "(3) Print shape details by index\n"; // הדפסת פרטי הצורה[cite: 1]
        cout << "(4) Exit\n"; // יציאה מהתוכנית[cite: 1]
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            // טיפול בחריגות - הקפדה על כך שקלט לא תקין יזרוק Exception מתאים[cite: 1]
            
            if (choice == 1) {
                // הוספת צורה לסוף המערך[cite: 1]
                // TODO: בקשת נתונים (סוג צורה, צבע, עובי, מידות) ויצירת אובייקט חדש[cite: 1]
                // שימוש ב- shapesArray.Add(newShape);
            } 
            else if (choice == 2) {
                // מחיקת צורה לפי אינדקס[cite: 1]
                // TODO: קליטת אינדקס, קריאה ל-shapesArray.remove(index) ושחרור הזיכרון (delete)[cite: 1]
            } 
            else if (choice == 3) {
                // הדפסת פרטי צורה ושימוש ב-RTTI[cite: 1]
                // TODO: קליטת אינדקס והדפסת area, perimeter, שדות נוספים.[cite: 1]
                // TODO: שימוש ב- dynamic_cast כדי לבדוק אם הצורה היא Square או OrthogonalTriangle ולהפעיל את draw()[cite: 1]
            }
        } 
        catch (const std::exception& e) {
            // תפיסת Exceptions (למשל על חריגה מהטווח) והדפסת הודעה, ללא קריסת התוכנית[cite: 1]
            cout << "Error: " << e.what() << ". Please try again.\n" << endl;
        }
    }

    // סיום ושחרור הזיכרון - מחיקת כל מצביעי Shape מתוך המערך ביציאה[cite: 1]
    return 0;
}