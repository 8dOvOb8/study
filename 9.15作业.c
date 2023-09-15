#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//首先定义一个链表节点结构来表示每个购物清单项：
struct ShoppingItem {
    char name[50]; // 商品名称
    int quantity; // 商品数量
    struct ShoppingItem* next;//指向下一个节点指针
};

//创建一个链表头指针，表示购物清单的起始点：
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
struct ShoppingItem* shoppingList1 = NULL;
//1. 添加商品到购物清单：
void addItem(char itemName[], int itemQuantity) {
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
    //此处填写若干语句；
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->next = shoppingList;
    shoppingList = newItem;
}
void addItem1(char itemName[], int itemQuantity) {
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
    //此处填写若干语句；
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->next = shoppingList1;
    shoppingList1 = newItem;
}

//2. 从购物清单中移除商品：
void removeItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            }
            else {
                shoppingList = current->next;
            }
            free(current);
            break;
        }
        //此处填写两行；
        previous = current;
        current = current->next;
    }
}

//3. 查看购物清单：
void displayList() {
    struct ShoppingItem* current = shoppingList;
    printf("购物清单:\n");
    while (current != NULL) {
        printf("%s - 数量：%d\n", current->name, current->quantity);
        //此处填写一句；
        current = current->next;
    }
}

//4. 修改购物清单中商品的数量：
void updateQuantity(char itemName[], int newItemQuantity) {
    struct ShoppingItem* current = shoppingList;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            //此处填写一句。
            current->quantity = newItemQuantity;
            break;
        }
        current = current->next;
    }
}

//5. 清空购物清单：
void clearList() {
    while (shoppingList != NULL) {
        //此处填写两句。
        struct ShoppingItem* temp = shoppingList;
        shoppingList = shoppingList->next;
        free(temp);
    }
}

//6. 计算购物清单中商品的总数量：
int totalQuantity() {
    struct ShoppingItem* current = shoppingList;
    int total = 0;
    while (current != NULL) {
        //此处填写两句；
        total += current->quantity;
        current = current->next;
    }
    return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    printf("查找商品 \"%s\" ：\n", itemName);
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            printf("%s - 数量：%d\n", current->name, current->quantity);
            return;
        }
        //此处填写一句。
        current = current->next;
    }
    printf("未找到商品 \"%s\"。\n", itemName);
}

//8. 排序购物清单：
void sortList() {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* nextItem = NULL;
    char tempName[50];
    int tempQuantity;
    while (current != NULL) {
        nextItem = current->next;
        while (nextItem != NULL) {
            if (strcmp(current->name, nextItem->name) > 0) {
                //交换商品信息
                //此处填写 3 句；
                strcpy(tempName, current->name);
                strcpy(current->name, nextItem->name);
                strcpy(nextItem->name, tempName);
                tempQuantity = current->quantity;
                current->quantity = nextItem->quantity;
                nextItem->quantity = tempQuantity;
            }
            nextItem = nextItem->next;
        }
        current = current->next;
    }
}

//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
    struct ShoppingItem* current = *list1;
    // 遍历到第一个购物清单的末尾
    //补充循环语句；
    while (current != NULL && current->next != NULL)
        current = current->next;
    // 将第二个购物清单连接到第一个清单的末尾
    current->next = *list2;
    *list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}

//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (prev == NULL) {
                // 如果要删除的是第一个节点
                struct ShoppingItem* temp = shoppingList;
                //填写一句；
                shoppingList = shoppingList->next;
                free(temp);
                if (!deleteAll) break;
            }
            else {
                // 如果要删除的不是第一个节点
                //填写一句；
                prev->next = current->next;
                free(current);
                current = prev->next;
                if (!deleteAll) break;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    //1. 添加商品到购物清单：
    //3. 查看购物清单：
    printf("添加商品到购物清单：\n");

    addItem("商品1", 1);
    addItem("商品2", 2);
    addItem("商品3", 3);
    addItem("商品4", 4);
    addItem("商品5", 5);
    addItem("商品6", 6);
    displayList();
    //4. 修改购物清单中商品的数量：
    //3. 查看购物清单：
    printf("\n修改购物清单中商品的数量：\n");
    updateQuantity("商品6", 10);
    displayList();

    //6. 计算购物清单中商品的总数量：
    printf("\n计算购物清单中商品的总数量：\n%d\n", totalQuantity());

    //7. 查找购物清单中的商品：
    printf("\n查找购物清单中的商品：\n");
    findItem("商品5");

    //8. 排序购物清单：
    //3. 查看购物清单：
    printf("\n排序购物清单：\n");
    sortList();
    displayList();

    //9. 合并购物清单：//假设你有两个不同的购物清单，你希望将它们合并成一个。
    //3. 查看购物清单：
    printf("\n合并购物清单：\n");
    addItem1("商品3", 3);
    addItem1("商品4", 4);
    mergeLists(&shoppingList, &shoppingList1);
    displayList();

    //2. 从购物清单中移除商品：
    //3. 查看购物清单：
    printf("\n从购物清单中移除商品：\n");
    removeItem("商品2");
    displayList();

    //10. 删除购物清单中的商品：//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，//可以选择删除其中一个或全部。
    //3. 查看购物清单：
    printf("\n删除购物清单中的商品：\n");
    deleteItem("商品3", 0);
    deleteItem("商品4", 1);
    displayList();

    //5. 清空购物清单：
    //3. 查看购物清单：
    printf("\n清空购物清单：\n");
    clearList();
    displayList();
    return 0;
}