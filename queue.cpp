#include<iostream>

// cấu trúc node gồm 2 phần
struct node {
    int data; // dữ liệu (ở đây là một số nguyên)
    struct node *next; // con trỏ trỏ đến node tiếp theo
};
typedef struct node NODE;

// cấu trúc của queue có 2 phần
struct queue {
    NODE *front; // con trỏ node ở đầu
    NODE *back; // con trỏ node ở cuối
};
typedef struct queue QUEUE;

// khởi tạo một node
NODE *createNode(int val) {
    NODE *p = new NODE;
    p->data = val;
    p->next = NULL;
    return p;
}

// khởi tạo một queue
void createQueue(QUEUE &q) {
    q.back = q.front = NULL;
}

// kiểm tra xem queue có rỗng không
bool isEmpty(QUEUE q) {
    // nếu điều kiện ở dưới đúng thì return true, ngược lại return false
    return q.front == NULL;
}

// kích thước queue
int size(QUEUE &q) {
    if (q.front == NULL) // nếu queue rỗng trả về 0
        return 0;
    else {
        NODE *p = q.front;
        int count = 0;
        while (p != NULL) {
            count++; // đếm
            p = p->next; // đi đến node tiếp theo khi nào p == NULL thì dừng
        }
        return count;
    }
}

// thêm một node vào queue
void push(QUEUE &q, int val) {
    NODE *p = createNode(val);
    if (isEmpty(q))
        // chưa có node nào thì node thêm vào là node đầu cũng là node cuối
        q.front = q.back = p;
    else {
        q.back->next = p; // node cuối trỏ đến node mới thêm
        q.back = p; // cập nhật lại node vừa thêm vào là node cuối của queue
    }
}

// xóa một node khỏi queue
void pop(QUEUE &q) {
    if (isEmpty(q))
        std::cout << "Queue is empty!";
    else {
        NODE *p = q.front; // cho node p trỏ vào node đầu của queue
        q.front = q.front->next; // cập nhật lại node đầu
        delete p; // xóa node p (xóa luôn node đầu vì node p đang trỏ đến node đầu)
    }
}

// xuất giá trị node đầu tiên (q.front) của queue
int top(QUEUE q) {
    return q.front->data;
}

int bot(QUEUE q) {
    return q.back->data;
}

int main() {
    QUEUE q;
    createQueue(q);
    for (int i = 1; i <= 5; i++)
        push(q, i);
    std::cout << "\nGia tri cuoi: " << bot(q);
    std::cout << "\nGia tri dau: " << top(q);
    std::cout << "\nKich thuoc queue: " << size(q);
    pop(q);
    std::cout << "\nGia tri dau tien (sau khi pop): " << top(q);
    std::cout << "\nGia tri cuoi: " << bot(q);
    std::cout << "\nKich thuoc queue: " << size(q);
    return 0;
}
