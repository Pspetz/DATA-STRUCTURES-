#include <iostream>

struct point{
    point* parent, *left, *right;

    int val = -1;
};

point* biggest;
point empty;

point search(int pos, bool near, point* loc = biggest){
    if(loc->val == pos){
        return *loc;
    } else if(loc->left->val != -1 and loc->val > pos){
        return search(pos, near, loc->left);
    } else if(loc->right->val != -1){
        return search(pos, near, loc->right);
    }

    if(near){
        return *loc;
    } else{
        point fail;
        return fail;
    }
}
void insert(int pos, point* res){
    point loc = search(pos, true);
    res->val = pos, res->left = &empty, res->right = &empty;
    res->parent = &loc; // <=== here

    if(loc.val < res->val){
        loc.left = res;
    } else{
        loc.right = res;
    }

}

void remove(int pos){

}

int pred(int pos){
    point res = search(pos, false);
    if(res.val == -1){
        return -1;
    }

}

int succ(int pos){
    point res = search(pos, false);
    if(res.val == -1){
        return -1;
    }

}

void inorder(point* pos = biggest){
    if(pos->left->val != -1){
        inorder(pos->left);
    }
    std::cout << pos->val << " ";
    if(pos->right->val != -1){
        inorder(pos->right);
    }
}

int main() {
    point start;
    start.parent = &empty, start.left = &empty, start.right = &empty;
    biggest = &start;
    char c;
    int pos;
    do{
        std::cin >> c >> pos;

        switch (c){
            case 'S':
                std::cout << search(pos, false).val << std::endl;
                break;
            case 'I':
                if(biggest->val == -1){
                    start.val = pos;
                } else{
                    point* res = new point;
                    insert(pos, res);
                }
                break;
            case 'R':
                remove(pos);
                break;
            case 'P':
                std::cout << pred(pos) << std::endl;
                break;
            case 'N':
                std::cout << succ(pos) << std::endl;
                break;
            case 'O':
                inorder();
                std::cout << std::endl;
                break;
        }
    } while(c != '0');
    return 0;
}
