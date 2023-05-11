#include <fstream>
#include <iostream>
#include <string>
using namespace std;

typedef struct mood_nod {
    int mood_point;
    struct mood_nod *link;
    struct student_nod *head;
} mood_node;

typedef struct student_nod {
    string name;
    string want_name;
    struct student_nod *next;
    struct gift_nod *give;
    struct gift_nod *get;
} student_node;

typedef struct gift_nod {
    string gift_name;
    bool gift_i;
    int given;
} gift_node;

int main() {
    string input;
    ifstream in;
    in.open("1.txt");
    getline(in, input);
    int n = stoi(input);

    mood_node m1, m2, m_2, m11, m_1, m;
    mood_node *ptr_m0, *ptr_m1, *ptr_m2, *ptr_m_1, *ptr_m_2, *list_head_node;

    ptr_m0 = &m1;
    ptr_m1 = &m11;
    ptr_m2 = &m2;
    ptr_m_1 = &m_1;
    ptr_m_2 = &m_2;
    list_head_node = ptr_m_2;
    ptr_m_2->link = ptr_m_1;
    ptr_m_1->link = ptr_m0;
    ptr_m0->link = ptr_m1;
    ptr_m1->link = ptr_m_2;

    student_node *curr = nullptr;
    student_node *input_order, *input_order_head;
    input_order = new student_node;
    input_order_head = input_order;

    m1.mood_point = 0;
    m2.mood_point = 2;
    m.mood_point = 0;
    m_2.mood_point = -2;
    m11.mood_point = 1;
    m_1.mood_point = -1;

    m1.head = NULL;
    m2.head = new student_node;
    m_2.head = new student_node;
    m.head = new student_node;
    m11.head = new student_node;
    m_1.head = new student_node;

    int k = 0;
    while (k < n) {
        student_node *ptr;
        gift_node *get_gift, *give_gift;
        ptr = new student_node;
        get_gift = new gift_node;
        give_gift = new gift_node;

        in >> ptr->name;
        in >> ptr->want_name;
        in >> give_gift->gift_name;
        in >> give_gift->gift_i;
        give_gift->given = 0;
        ptr->give = give_gift;

        if (k == 0) {
            m1.head = ptr;
            curr = m1.head;
            input_order_head->name = ptr->name;
            input_order_head->next = new student_node;
            input_order = input_order_head->next;
            k++;

        } else {
            curr->next = ptr;
            curr = curr->next;
            input_order->name = ptr->name;
            input_order->next = new student_node;
            input_order = input_order->next;
            k++;
        }
        curr->next = NULL;
    }

    student_node *ptr, *p_head;
    ptr = new student_node;
    p_head = ptr;
    string p_name;
    int p_num = 0;
    while (in >> p_name) {
        p_num++;
        ptr->name = p_name;
        ptr->next = new student_node;

        ptr = ptr->next;
    }

    curr = m1.head;

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int tem = j;
            student_node *curr = nullptr;
            curr = m1.head;

            while (tem > 0) {
                curr = curr->next;
                tem--;
            }
            if (curr->name > curr->next->name) {
                swap(curr->name, curr->next->name);
                swap(curr->want_name, curr->next->want_name);
                swap(curr->give, curr->next->give);
            }
        }
    }
    curr = m1.head;
    cout << "0";
    for (int i = 0; i < n; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(0)";
        curr = curr->next;
    }
    cout << endl;
    student_node *p_curr, *curr2, *curr3 = nullptr, *curr4;
    curr = m1.head;
    curr2 = m1.head;
    p_curr = p_head;

    student_node *curr_mood_2 = nullptr, *curr_mood__2 = nullptr;
    int num_m2 = 0;
    int num_m_2 = 0;

    for (int i = 0; i < p_num; i++) {
        curr = m1.head;
        int tem = i;
        bool find = false;
        p_curr = p_head;
        while (tem > 0) {
            p_curr = p_curr->next;
            tem--;
        }
        //        cout << p_curr->name<<endl;

        for (int j = 0; j < n; j++) {
            if (curr->name == p_curr->name) {
                curr2 = m1.head;
                for (int mm = 0; mm < n; mm++) {
                    if (curr2->name == curr->want_name) {
                        if (curr2->give->given == 0) {
                            curr2->give->given = 1;
                            curr->get = curr2->give;
                            if (curr2->give->gift_i == 1) {
                                if (num_m2 == 0) {
                                    m2.head->name = curr->name;
                                    m2.head->get = curr->get;
                                    curr_mood_2 = m2.head;
                                    num_m2++;
                                    find = true;
                                } else {
                                    curr_mood_2->next = new student_node;
                                    curr_mood_2->next->name = curr->name;
                                    curr_mood_2->next->get = curr->get;
                                    curr_mood_2 = curr_mood_2->next;
                                    num_m2++;
                                    find = true;
                                }

                            } else {
                                if (num_m_2 == 0) {
                                    m_2.head->name = curr->name;
                                    m_2.head->get = curr->get;
                                    curr_mood__2 = m_2.head;
                                    num_m_2++;
                                    find = true;
                                } else {
                                    curr_mood__2->next = new student_node;
                                    curr_mood__2->next->name = curr->name;
                                    curr_mood__2->next->get = curr->get;
                                    curr_mood__2 = curr_mood__2->next;
                                    num_m_2++;
                                    find = true;
                                }
                            }
                        }
                        break;
                    }
                    curr2 = curr2->next;
                }
                break;
            }
            curr = curr->next;
            //            cout << 1;
        }
    }
    curr = m_2.head;
    cout << endl;
    cout << "-2";
    for (int i = 0; i < num_m_2; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(" << curr->get->gift_name << ")";
        curr = curr->next;
    }
    curr = m1.head;
    cout << endl;
    cout << "0";
    for (int i = 0; i < n; i++) {
        if (curr->get == NULL) {
            cout << " -> ";
            cout << curr->name;
            cout << "(0)";
        }
        curr = curr->next;
    }

    curr = m2.head;
    cout << endl;
    cout << "2";
    for (int i = 0; i < num_m2; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(" << curr->get->gift_name << ")";
        curr = curr->next;
    }

    curr = input_order_head;

    student_node *curr_mood_1 = nullptr, *curr_mood__1 = nullptr;
    int num_m11 = 0;
    int num_m_1 = 0;
    int num_m = 0;
    curr = input_order_head;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            curr2 = m1.head;
            int tem_j = j;
            while (tem_j > 0) {
                tem_j--;
                curr2 = curr2->next;
            }
            if (curr2->name == curr->name) {
                if (num_m == 0) {
                    m.head->name = curr2->name;
                    m.head->want_name = curr2->want_name;
                    m.head->give = curr2->give;
                    m.head->get = curr2->get;
                    curr3 = m.head;
                    curr3->next = new student_node;
                    curr3 = curr3->next;
                    num_m++;
                } else {
                    curr3->name = curr2->name;
                    curr3->want_name = curr2->want_name;
                    curr3->give = curr2->give;
                    curr3->get = curr2->get;
                    curr3->next = new student_node;
                    curr3 = curr3->next;
                    num_m++;
                }
            }
        }

        curr = curr->next;
    }
    cout << endl
         << endl;

    curr = m.head;
    for (int i = 0; i < n; i++) {
        if (curr->get == NULL) {
            for (int j = 0; j < n; j++) {
                curr2 = m.head;
                int tem_j = j;
                while (tem_j > 0) {
                    curr2 = curr2->next;
                    tem_j--;
                }
                if (curr->name == curr2->name) continue;
                if (curr2->give->given == 0) {
                    curr2->give->given = 1;
                    curr->get = curr2->give;
                    if (curr2->give->gift_i == 1) {
                        if (num_m11 == 0) {
                            m11.head->name = curr->name;
                            m11.head->get = curr->get;
                            curr_mood_1 = m11.head;
                            num_m11++;

                        } else {
                            curr_mood_1->next = new student_node;
                            curr_mood_1->next->name = curr->name;
                            curr_mood_1->next->get = curr->get;
                            curr_mood_1 = curr_mood_1->next;
                            num_m11++;
                        }

                    } else {
                        if (num_m_1 == 0) {
                            m_1.head->name = curr->name;
                            m_1.head->get = curr->get;
                            curr_mood__1 = m_1.head;
                            num_m_1++;

                        } else {
                            curr_mood__1->next = new student_node;
                            curr_mood__1->next->name = curr->name;
                            curr_mood__1->next->get = curr->get;
                            curr_mood__1 = curr_mood__1->next;
                            num_m_1++;
                        }
                        break;
                    }
                    break;
                }
            }
        }

        curr = curr->next;
    }

    curr = m11.head;

    for (int i = num_m11 - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int tem = j;
            student_node *curr = nullptr;
            curr = m11.head;

            while (tem > 0) {
                curr = curr->next;
                tem--;
            }
            if (curr->name > curr->next->name) {
                swap(curr->name, curr->next->name);
                swap(curr->want_name, curr->next->want_name);
                swap(curr->give, curr->next->give);
                swap(curr->get, curr->next->get);
            }
        }
    }
    curr = m_1.head;

    for (int i = num_m_1 - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int tem = j;
            student_node *curr = nullptr;
            curr = m_1.head;

            while (tem > 0) {
                curr = curr->next;
                tem--;
            }
            if (curr->name > curr->next->name) {
                swap(curr->name, curr->next->name);
                swap(curr->want_name, curr->next->want_name);
                swap(curr->give, curr->next->give);
                swap(curr->get, curr->next->get);
            }
        }
    }

    curr = m_2.head;
    cout << "-2";
    for (int i = 0; i < num_m_2; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(" << curr->get->gift_name << ")";
        curr = curr->next;
    }
    curr = m_1.head;
    cout << endl;
    cout << "-1";
    for (int i = 0; i < num_m_1; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(" << curr->get->gift_name << ")";
        curr = curr->next;
    }
    curr = m11.head;
    cout << endl;
    cout << "1";
    for (int i = 0; i < num_m11; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(" << curr->get->gift_name << ")";
        curr = curr->next;
    }

    curr = m2.head;
    cout << endl;
    cout << "2";
    for (int i = 0; i < num_m2; i++) {
        cout << " -> ";
        cout << curr->name;
        cout << "(" << curr->get->gift_name << ")";
        curr = curr->next;
    }

    curr = m.head;
    cout << endl
         << endl;
    for (int i = 0; i < n; i++) {
        curr = m.head;
        int tem_i = i;
        while (tem_i > 0) {
            curr = curr->next;
            tem_i--;
        }
        cout << curr->name << " ";
        cout << curr->get->gift_name;
        cout << " ";

        int point = 0;
        for (int j = 0; j < n; j++) {
            int tem_j = j;
            curr2 = m.head;
            while (tem_j > 0) {
                curr2 = curr2->next;
                tem_j--;
            }
            if (curr2->give->gift_name == curr->get->gift_name) {
                if (curr2->name == curr->want_name) {
                    if (curr->get->gift_i == 1)
                        point = 2;
                    else
                        point = -2;
                } else {
                    if (curr->get->gift_i == 1)
                        point = 1;
                    else
                        point = -1;
                }
                break;
            }
        }

        switch (point) {
            case 1:
                cout << ":)";
                break;
            case -1:
                cout << ":(";
                break;
            case 2:
                cout << ":)))";
                break;
            case -2:
                cout << ":(((";
                break;

            default:
                break;
        }

        cout << endl;
    }
    return 0;
}
