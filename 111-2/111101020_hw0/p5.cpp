#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct gift_node {
    string gift_name;
    int good;
    bool given;
};
struct student_node {
    int mood;
    string name;
    string want_name;
    gift_node give;
    gift_node get;
    student_node *next;
};
struct mood_node {
    int mood;
    student_node *to_stu;
    mood_node *m_next;
};

int main(int argc, char*argv[]) {
    ifstream in(argv[1]);
    string ss;

    // get size
    int size;
    in >> ss;
    size = stoi(ss);
    mood_node *head_m, *ptr_m, *curr_m;
    student_node *head_s, *ptr_s, *curr_s, *h_seq, *p_seq, *c_seq;

    // list_head_node
    ptr_m = new mood_node;
    head_m = ptr_m;
    curr_m = ptr_m;

    // create list_mood_node of -2 ~ 2
    for (int i = -2; i <= 2; i++) {
        ptr_m = new mood_node;
        ptr_m->mood = i;
        curr_m->m_next = ptr_m;
        curr_m = ptr_m;
    }

    // create NULL space of student_node
    ptr_s = new student_node;
    curr_s = ptr_s;
    head_s = ptr_s;
    p_seq = new student_node;
    c_seq = p_seq;
    h_seq = p_seq;

    // find mood '0'
    ptr_m = head_m;
    while (ptr_m->mood != 0) {
        ptr_m = ptr_m->m_next;
    }

    // connect the mood and student
    ptr_m->to_stu = ptr_s;

    for (int i = 0; i < size; i++) {  // input the data to the link list
        int tt;
        ptr_s = new student_node;
        p_seq = new student_node;
        curr_s->next = ptr_s;
        c_seq->next = p_seq;
        curr_s = ptr_s;
        c_seq = p_seq;
        in >> ss;
        ptr_s->name = ss;
        p_seq->name = ss;
        in >> ss;
        ptr_s->want_name = ss;
        in >> ss;
        ptr_s->give.gift_name = ss;
        p_seq->give.gift_name = ss;
        in >> tt;
        ptr_s->give.good = tt;
        p_seq->give.good = tt;
        ptr_s->give.given = false;
        p_seq->give.given = false;
        ptr_s->next = NULL;
        p_seq->next = NULL;
        ptr_s->get.gift_name = "0";
        p_seq->get.gift_name = "0";
    }

    // sort the list according to name
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int temp = j;
            student_node *curr = nullptr;
            curr = head_s->next;
            while (temp > 0) {
                curr = curr->next;
                temp--;
            }
            if (curr->name > curr->next->name) {
                swap(curr->name, curr->next->name);
                swap(curr->want_name, curr->next->want_name);
                swap(curr->give, curr->next->give);
            }
        }
    }

    // initial part output
    cout << ptr_m->mood << " -> ";
    ptr_s = head_s->next;
    while (ptr_s->next) {
        cout << ptr_s->name << "(0) -> ";
        ptr_s = ptr_s->next;
    }
    cout << ptr_s->name << "(0)" << endl
         << endl;

    // already read the all file
    // part1 host and friend1 ...
    while (in >> ss) {
        ptr_s = head_s->next;
        student_node *curr;
        for (int i = 0; i < size; i++) {
            bool flag = false;
            if (ptr_s->name == ss) {
                curr = head_s->next;
                for (int j = 0; j < size; j++) {
                    if (ptr_s->want_name == curr->name) {
                        if (curr->give.given) {
                            flag = true;
                            break;
                        }
                        ptr_s->get.gift_name = curr->give.gift_name;
                        ptr_s->get.given = true;
                        curr->give.given = true;

                        // not be sorted input data
                        p_seq = h_seq->next;
                        while (p_seq->name != curr->name) {
                            p_seq = p_seq->next;
                        }
                        p_seq->give.given = true;

                        p_seq = h_seq->next;
                        while (p_seq->name != ptr_s->name) {
                            p_seq = p_seq->next;
                        }
                        p_seq->get.given = true;
                        p_seq->get.gift_name = curr->give.gift_name;

                        if (curr->give.good == 0) {
                            p_seq->mood = -2;
                            ptr_s->mood = -2;
                        } else {
                            p_seq->mood = 2;
                            ptr_s->mood = 2;
                        }
                    } else {
                        curr = curr->next;
                    }
                }
            } else {
                ptr_s = ptr_s->next;
            }
            if (flag) {
                flag = false;
                break;
            }
        }
    }

    // connect -2
    ptr_m = head_m;
    while (ptr_m->mood != -2) {
        ptr_m = ptr_m->m_next;
    }

    // create NULL student node place of -2
    curr_s = new student_node;  // NULL
    ptr_m->to_stu = curr_s;

    ptr_s = head_s->next;
    while (ptr_s) {
        if (ptr_s->mood == -2) {
            student_node *curr = curr_s;
            // new new space
            curr_s = new student_node;
            curr->next = curr_s;
            curr = curr_s;
            curr_s->next = NULL;

            // copy
            curr_s->name = ptr_s->name;
            curr_s->want_name = ptr_s->want_name;
            curr_s->get.given = true;
            curr_s->get.gift_name = ptr_s->get.gift_name;
            curr_s->get.good = ptr_s->get.good;
            curr_s->give.given = ptr_s->give.given;
            curr_s->give.gift_name = ptr_s->give.gift_name;
            curr_s->give.good = ptr_s->give.good;
            curr_s->mood = ptr_s->mood;

            // delete
            student_node *temp = head_s;
            while (temp->next->name != ptr_s->name) {
                temp = temp->next;
            }
            if (ptr_s->next == NULL){
                temp->next = nullptr;  
                delete ptr_s; 
                ptr_s = head_s->next;  
                break;
            }
            curr = ptr_s->next;
            temp->next = curr;
            ptr_s->next = NULL;
            delete ptr_s;
            ptr_s = head_s->next;

        } else {
            ptr_s = ptr_s->next;
        }
    }

    ptr_m = head_m;
    while (ptr_m->mood != 2) {
        ptr_m = ptr_m->m_next;
    }

    // create NULL student node place of 2
    curr_s = new student_node;  // NULL
    ptr_m->to_stu = curr_s;

    ptr_s = head_s->next;
    while (ptr_s) {
        if (ptr_s->mood == 2) {
            student_node *curr = curr_s;
            // new new space
            curr_s = new student_node;
            curr->next = curr_s;
            curr = curr_s;
            curr_s->next = NULL;

            // copy
            curr_s->name = ptr_s->name;
            curr_s->want_name = ptr_s->want_name;
            curr_s->get.given = true;
            curr_s->get.gift_name = ptr_s->get.gift_name;
            curr_s->get.good = ptr_s->get.good;
            curr_s->give.given = ptr_s->give.given;
            curr_s->give.gift_name = ptr_s->give.gift_name;
            curr_s->give.good = ptr_s->give.good;
            curr_s->mood = ptr_s->mood;

            // delete be sorted list
            student_node *temp = head_s;
            while (temp->next->name != ptr_s->name) {
                temp = temp->next;
            }
            if (ptr_s->next == NULL){
                temp->next = nullptr;  
                delete ptr_s; 
                ptr_s = head_s->next;  
                break;
            }
            curr = ptr_s->next;
            temp->next = curr;
            ptr_s->next = NULL;
            delete ptr_s;
            ptr_s = head_s->next;

        } else {
            ptr_s = ptr_s->next;
        }
    }

    // part1 output
    for (int i = -1; i <= 1; i++) {
        ptr_m = head_m;
        while (ptr_m->mood != 2 * i) {
            ptr_m = ptr_m->m_next;
        }
        ptr_s = ptr_m->to_stu->next;
        cout << 2 * i << " -> ";
        while (ptr_s->next) {
            cout << ptr_s->name << "(" << ptr_s->get.gift_name << ") -> ";
            ptr_s = ptr_s->next;
        }
        cout << ptr_s->name << "(" << ptr_s->get.gift_name << ")" << endl;
    }
    cout << endl;

    // part two change (only sequence be change)
    p_seq = h_seq->next;
    c_seq = p_seq->next;
    while (p_seq) {
        if (!p_seq->get.given) {
            // cout << p_seq->name << " ";
            while (c_seq) {
                if (!c_seq->give.given) {
                    if (c_seq->name == p_seq->name) {
                        p_seq = p_seq->next;
                        break;
                    }
                    p_seq->get.gift_name = c_seq->give.gift_name;
                    p_seq->get.good = c_seq->give.good;
                    // cout << p_seq->name << " " << p_seq->get.gift_name << " " << p_seq->get.good << endl;
                    if (c_seq->give.good == 0) {
                        p_seq->mood = -1;
                    } else {
                        p_seq->mood = 1;
                    }
                    p_seq->get.given = true;
                    c_seq->give.given = true;
                    // p_seq = p_seq->next;
                    break;
                } else {
                    c_seq = c_seq->next;
                }
            }
            p_seq = p_seq->next;
        } else {
            p_seq = p_seq->next;
        }
        c_seq = h_seq->next;
    }

    p_seq = h_seq->next;
    // while (p_seq) {
    //     if (p_seq->get.gift_name != "0") {
    //         cout << p_seq->name << " " << p_seq->get.gift_name << endl;
    //     }
    //     p_seq = p_seq->next;
    // }

    // copy to the mood list
    ptr_m = head_m;
    while (ptr_m->mood != 0) {
        ptr_m = ptr_m->m_next;
    }

    ptr_s = ptr_m->to_stu->next;
    curr_s = h_seq->next;

    while (ptr_s) {
        while (curr_s) {
            if (curr_s->name == ptr_s->name) {
                ptr_s->get.gift_name = curr_s->get.gift_name;
                ptr_s->get.good = curr_s->get.good;
                ptr_s->mood = curr_s->mood;
                break;
            } else {
                curr_s = curr_s->next;
            }
        }
        ptr_s = ptr_s->next;
        curr_s = h_seq->next;
    }

    // connect the student node and mood node of -1
    ptr_m = head_m;
    while (ptr_m->mood != -1) {
        ptr_m = ptr_m->m_next;
    }
    curr_s = new student_node;  // NULL
    ptr_m->to_stu = curr_s;

    ptr_s = head_s->next;
    while (ptr_s) {
        if (ptr_s->mood == -1) {
            student_node *curr = curr_s;
            // new new space
            curr_s = new student_node;
            curr->next = curr_s;
            curr = curr_s;
            curr_s->next = NULL;

            // copy
            curr_s->name = ptr_s->name;
            curr_s->want_name = ptr_s->want_name;
            curr_s->get.given = true;
            curr_s->get.gift_name = ptr_s->get.gift_name;
            curr_s->get.good = ptr_s->get.good;
            curr_s->give.given = ptr_s->give.given;
            curr_s->give.gift_name = ptr_s->give.gift_name;
            curr_s->give.good = ptr_s->give.good;
            curr_s->mood = ptr_s->mood;

            // delete
            student_node *temp = head_s;
            while (temp->next->name != ptr_s->name) {
                temp = temp->next;
            }
            if (ptr_s->next == NULL){
                temp->next = nullptr;  
                delete ptr_s; 
                ptr_s = head_s->next;  
                break;
            }
            curr = ptr_s->next;
            temp->next = curr;
            ptr_s->next = NULL;
            delete ptr_s;
            ptr_s = head_s->next;

        } else {
            ptr_s = ptr_s->next;
        }
    }

    // connect the student node and mood node of 1
    ptr_m = head_m;
    while (ptr_m->mood != 1) {
        ptr_m = ptr_m->m_next;
    }
    curr_s = new student_node;  // NULL
    ptr_m->to_stu = curr_s;

    ptr_s = head_s->next;
    while (ptr_s) {
        if (ptr_s->mood == 1) {
            student_node *curr = curr_s;
            // new new space
            curr_s = new student_node;
            curr->next = curr_s;
            curr = curr_s;
            curr_s->next = NULL;

            // copy
            curr_s->name = ptr_s->name;
            curr_s->want_name = ptr_s->want_name;
            curr_s->get.given = true;
            curr_s->get.gift_name = ptr_s->get.gift_name;
            curr_s->get.good = ptr_s->get.good;
            curr_s->give.given = ptr_s->give.given;
            curr_s->give.gift_name = ptr_s->give.gift_name;
            curr_s->give.good = ptr_s->give.good;
            curr_s->mood = ptr_s->mood;

            // delete
            student_node *temp = head_s;
            while (temp->next->name != ptr_s->name) {
                temp = temp->next;
            }
            if (ptr_s->next == NULL){
                temp->next = nullptr;  
                delete ptr_s; 
                ptr_s = head_s->next;  
                break;
            }
            curr = ptr_s->next;
            temp->next = curr;
            ptr_s->next = NULL;
            delete ptr_s;
            ptr_s = head_s->next;

        } else {
            ptr_s = ptr_s->next;
        }
    }

    // part 2 output
    for (int i = -2; i <= 2; i++) {
        if (i == 0) continue;
        ptr_m = head_m;
        while (ptr_m->mood != i) {
            ptr_m = ptr_m->m_next;
        }
        ptr_s = ptr_m->to_stu->next;
        cout << i << " -> ";
        while (ptr_s->next) {
            cout << ptr_s->name << "(" << ptr_s->get.gift_name << ") -> ";
            ptr_s = ptr_s->next;
        }
        cout << ptr_s->name << "(" << ptr_s->get.gift_name << ")" << endl;
    }
    cout << endl;

    // last output
    p_seq = h_seq->next;
    while (p_seq) {
        cout << p_seq->name << " " << p_seq->get.gift_name << " ";
        switch (p_seq->mood) {
            case -2:
                cout << ":(((" << endl;
                break;
            case -1:
                cout << ":(" << endl;
                break;
            case 1:
                cout << ":)" << endl;
                break;
            case 2:
                cout << ":)))" << endl;
                break;
        }
        p_seq = p_seq->next;
    }
    return 0;
}

