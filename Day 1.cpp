#include <bits/stdc++.h>
using namespace std;

/*
note: the code will be update step by step as l learn new concepts
      aiming to become more powerful and professional over time
*/

//    class definition
class chess {

private:
    /* private member
       can only be accessed inside the class
       used for data hiding (encapsulation) 
    */
    bool checkmate;

public:
    /* 
       public data members
       accessible from outside the class
    */
    string name;
    int move;

    /* 
       setter function
       used to modify private variable
       demonstrates encapsulation 
       */
    void set(bool move) {
        checkmate = move;
    }

    /* 
       getter function
       returns private variable value
       const = does not modify object 
    */
    bool get() const {
        return checkmate;
    }

    /*
       member function declaration
       defined outside class using :: 
    */
    void show(const string& name, int move) const;
};

/* defined outside class using (outside class) */
void chess::show(const string& name, int move) const {

    /* prints object data */
    cout << name << ' ' << move << '\n';
}

void done() {

    /* object creation (instances of class) */
    chess rook, king;

    /* accessing public members */
    king.move = 0;

    rook.name = "Rook";
    rook.move = 2;

    /* using setter to store condition result */
    rook.set(king.move == 0);

    /* ternary operator:
       prints YES if both conditions are true,
       otherwise NO 
    */
    cout << ((rook.get() && king.move == 0)
        ? "YES"
        : "NO") << '\n';

    /* calling member function */
    rook.show(rook.name, rook.move);
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    done();

    return 0;
}
