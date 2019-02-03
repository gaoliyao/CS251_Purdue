#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "stack.h"
#include "circular_deque.h"
using namespace std;

ifstream inputfile;
ofstream outputfile;

void read_part_1()
{
    // TODO: Part1 : Create stack
    Stack stack = Stack();
    string str;
    getline(inputfile, str);
    int time;
    stringstream convert(str);
    convert >> time;
    for (int i = 0; i < time; i++) {
        getline(inputfile, str);
        char oper = '0';
        stringstream convert(str);
        convert >> oper;
        if (oper == 'i') {
            int a, b;
            convert >> a;
            convert >> b;
            Pair p(a, b);
            stack.push(p);
            // stack.print()
        }
        else {
            if (stack.isEmpty()) {
                outputfile << "empty" << endl;
            }
            else {
                Pair p = stack.pop();
                // stack.print();
                outputfile<<p.getNum1()<<" "<<p.getNum2()<<endl;
            }
        }
    }
}

void read_part_2()
{
    //TODO: Part 2: Run the word search
    cout<<"Task 2"<<endl;
    int line, row;
    inputfile>>line>>row;
    char letters[line][row] = {'0'};

    for (int i = 0; i < line; i++) {
        for (int j = 0; j < row; j++) {
            char c;
            inputfile>>c;
            letters[i][j] = c;
        }
    }
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < row; j++) {
            cout<<letters[i][j];
        }
        cout<<endl;
    }

    Stack wordStack = Stack();
    string word;
    inputfile >> word;
    cout << word << endl;
    int searchIndex = 0;
    char searchC = word[0];
    // wordStack = search(wordStack, word, 0);
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < row; j++) {
            if (letters[i][j] == searchC) {
                Pair p(i, j);
                p.setIndex(0);
                wordStack.push(p);
            }
        }
    }
    while (!wordStack.isEmpty() && wordStack.peek()->data.getIndex() != word.length() - 1) {
        if (wordStack.peek()->data.checked == true) {
            wordStack.pop();
            continue;
        }
        int i = wordStack.peek()->data.getIndex();
        wordStack.peek()->data.checked = true;
        i = i + 1;
        searchC = word[i];
        int lineId = wordStack.peek()->data.getNum1();
        int rowId = wordStack.peek()->data.getNum2();
        for (int p = lineId-1; p <= lineId+1; p++) {
            for (int q = rowId-1; q <= rowId+1; q++) {
                if (p >= 0 && p < line && q >= 0 && q < row && !(p == lineId && q == rowId)) {
                    if (letters[p][q] == searchC) {
                        Pair pair2(p, q);
                        pair2.setIndex(i);
                        wordStack.push(pair2);
                    }
                }
            }
        }
        if (wordStack.peek()->data.getIndex() != i) {
            wordStack.pop();
        }
    }
    if (wordStack.isEmpty()) {
        cout<<"not found"<<endl;
    }
    else{
        Stack reverseStack = Stack();
        int index = wordStack.peek()->data.getIndex();
        while (!wordStack.isEmpty()) {
            if (wordStack.peek()->data.getIndex() == index) {
                reverseStack.push(wordStack.pop());
                index--;
            }
            else {
                wordStack.pop();
            }
        }
        while (!reverseStack.isEmpty()) {
            Pair p = reverseStack.pop();
            outputfile << p.getNum1() << " " << p.getNum2() << endl;
        }
        cout<<"found"<<endl;
    }
}

void read_part_3()
{
    //TODO: Part 3: Circular double ended queue
    Deque deque = Deque();
    cout<<"Task 3"<<endl;
    int lineMax = 0;
    inputfile >> lineMax;
    for (int i = 0; i < lineMax; i++) {
        cout << "before operation: " << endl;
        deque.print();
        char c1;
        inputfile >> c1;
        if (c1 == 'e'){
            char c2;
            inputfile >> c2;
            if (c2 == 'f') {
                int num;
                inputfile >> num;
                cout << "e f " << num << endl;
                deque.enqueue_front(num);
            }
            if (c2 == 'b') {
                int num;
                inputfile >> num;
                cout << "e b " << num << endl;
                deque.enqueue_back(num);
            }

        }
        else if (c1 == 'd'){
            char c2;
            inputfile >> c2;
            if (c2 == 'f') {
                cout << "d f ";
                outputfile << deque.dequeue_front() << endl;
            }
            if (c2 == 'b') {
                cout << "d b ";
                outputfile << deque.dequeue_back() << endl;
            }
        }
        else if (c1 == 's') {
            cout << "s ";
            outputfile << deque.print_array_size() << " ";
            outputfile << deque.print_front_index() << " ";
            outputfile << deque.print_rear_index() << endl;
        }
        else {

        }
        cout << "after operation: " << endl;
        deque.print();
        cout << "================" << endl;
    }
}

int main(int argc, char *argv[])
{
    // Read in the test case


    inputfile.open(argv[1]);
    outputfile.open(argv[2]);

    string str;

    getline(inputfile, str);
    int part;
    stringstream convert(str);
    convert >> part;

    switch(part)
    {
        case 1:
            read_part_1();
            break;
        case 2:
            read_part_2();
            break;
        case 3:
            read_part_3();
            break;
    }

    inputfile.close();
    outputfile.close();

    return 0;
}
