#include "differentiate.h"
#include <sstream>

Differentiate::Differentiate() {
    p = new Parser();
    v = new Valid();
}

Differentiate::~Differentiate() {
    delete p;
    delete v;
}

vector<Node> Differentiate::differentiate(vector<Node> tree) {
    deque<Node> expression = vectorToDeque(tree);
    expression.push_front(p->createNode("delta", constants::DELTA, 1));
    deque<Node> temp = doDifferentiation(expression);
    vector<Node> differentiatedExpression;
    for (unsigned int i = 0; i < temp.size(); i++) {
        differentiatedExpression.push_back(temp[i]);
    }
    return differentiatedExpression;
}

deque<Node> Differentiate::vectorToDeque(vector<Node> tree) {
    deque<Node> temp;
    for (unsigned int i = 0; i < tree.size(); i++) {
        temp.push_back(tree[i]);
    }
    return temp;
}

deque<Node> Differentiate::doDifferentiation(deque<Node> tree) {
    int i = 0;
    Printer p;
    while (i < tree.size()) {
        if (tree[i].type == constants::DELTA) {
            bool reset = true;
            int j = tree[i+1].type;
            switch(j) {
                case 0:
                case 1:
                    differentiatePlusMinus(tree, i);
                    break;
                case 3:
                    if (tree[i+1].oper == "x") {
                        differentiateX(tree, i);
                        break;
                    }
                case 2:
                case 9:
                    differentiateNumber(tree, i);
                    break;
                case 4:
                    differentiatePower(tree, i);
                    break;
                case 5:
                    differentiateTimes(tree, i);
                    break;
                case 6:
                    differentiateDivision(tree, i);
                    break;
                case 7:
                case 8:
                    differentiateSinCos(tree, i);
                    break;
                case 11:
                    i++;
                    reset = false;
                    break;
                default:
                    cout << "Wrong operator" << endl;
            }
            if (reset) {
                i = 0;
            }
        }
        else {
            i++;
        }
    }
    return tree;
}

void Differentiate::differentiatePlusMinus(deque<Node> &tree, int index) {
    stringstream s;
    for (int i = 0; i < index; i++) {
        s << tree[i] << " ";
    }
    string l = subtreeToStringstream(tree, index + 2);
    int indexRightChild = lastIndexSubTree(tree, index + 2) + 1;
    string r = subtreeToStringstream(tree, indexRightChild);
    s << (tree[index+1].oper == "+" ? " +" : " -") << " delta " << l << " delta " << r << " ";
    for (int i = lastIndexSubTree(tree, indexRightChild) + 1; i < tree.size(); i++) {
        s << tree[i] << " ";
    }
    tree = p->dequeParseInput(s.str());
}

void Differentiate::differentiateX(deque<Node> &tree, int index) {
    tree.erase(tree.begin()+index+1);
    tree[index] = p->createNode("1", constants::NUMBER, 0);
}

void Differentiate::differentiateNumber(deque<Node> &tree, int index) {
    tree.erase(tree.begin()+index+1);
    tree[index] = p->createNode("0", constants::NUMBER, 0);
}

void Differentiate::differentiatePower(deque<Node> &tree, int index) {
    stringstream s;
    for (int i = 0; i < index; i++) {
        s << tree[i] << " ";
    }
    string l = subtreeToStringstream(tree, index + 2);
    int indexRightChild = lastIndexSubTree(tree, index + 2) + 1;
    Node rightChild = tree[indexRightChild];
    rightChild.value--;
    s << " * * " << tree[indexRightChild] << " ^ " << l << " " << rightChild << " delta " << l << " ";
    for (int i = indexRightChild + 1; i < tree.size(); i++) {
        s << tree[i] << " ";
    }
    tree = p->dequeParseInput(s.str());
}

void Differentiate::differentiateTimes(deque<Node> &tree, int index) {
    stringstream s;
    for (int i = 0; i < index; i++) {
        s << tree[i] << " ";
    }
    string l = subtreeToStringstream(tree, index + 2);
    int indexRightChild = lastIndexSubTree(tree, index + 2) + 1;
    string r = subtreeToStringstream(tree, indexRightChild);
    s << " + * delta " << l << " " << r << " * " << l << " delta " << r << " ";
    for (int i = lastIndexSubTree(tree, indexRightChild) + 1; i < tree.size(); i++) {
        s << tree[i] << " ";
    }
    tree = p->dequeParseInput(s.str());
}

void Differentiate::differentiateDivision(deque<Node> &tree, int index) {
    stringstream s;
    for (int i = 0; i < index; i++) {
        s << tree[i] << " ";
    }
    string l = subtreeToStringstream(tree, index + 2);
    int indexRightChild = lastIndexSubTree(tree, index + 2) + 1;
    string r = subtreeToStringstream(tree, indexRightChild);
    s << " / - * delta " << l << " " << r << " * " << l << " delta " << r << " ^ " << r << " 2 ";
    for (int i = lastIndexSubTree(tree, indexRightChild) + 1; i < tree.size(); i++) {
        s << tree[i] << " ";
    }
    tree = p->dequeParseInput(s.str());
}

void Differentiate::differentiateSinCos(deque<Node> &tree, int index) {
    stringstream s;
    for (int i = 0; i < index; i++) {
        s << tree[i] << " ";
    }
    string r = subtreeToStringstream(tree, index + 2);
    if (tree[index+1].type == constants::SIN) {
        s << " * cos " << r << " delta " << r << " ";
    }
    else {
        s << " * * -1 sin " << r << " delta " << r << " ";
    }
    for (int i = lastIndexSubTree(tree, index + 2) + 1; i < tree.size(); i++) {
        s << tree[i] << " ";
    }
    tree = p->dequeParseInput(s.str());
}

string Differentiate::subtreeToStringstream(deque<Node> tree, int index) {
    stringstream s;
    int indexLastNode = lastIndexSubTree(tree, index);
    s << tree[index];
    for (int i = index + 1; i <= indexLastNode; i++) {
        s << " " << tree[i];
    }
    return s.str();
}

int Differentiate::lastIndexSubTree(deque<Node> tree, int index) {
    int arity = 1;
    while (arity != 0) {
        arity += tree[index].arity - 1;
        index++;
    }
    return index - 1;
}