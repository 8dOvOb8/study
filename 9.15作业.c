#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���ȶ���һ������ڵ�ṹ����ʾÿ�������嵥�
struct ShoppingItem {
    char name[50]; // ��Ʒ����
    int quantity; // ��Ʒ����
    struct ShoppingItem* next;//ָ����һ���ڵ�ָ��
};

//����һ������ͷָ�룬��ʾ�����嵥����ʼ�㣺
struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
struct ShoppingItem* shoppingList1 = NULL;
//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
    //�˴���д������䣻
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->next = shoppingList;
    shoppingList = newItem;
}
void addItem1(char itemName[], int itemQuantity) {
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
    //�˴���д������䣻
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->next = shoppingList1;
    shoppingList1 = newItem;
}

//2. �ӹ����嵥���Ƴ���Ʒ��
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
        //�˴���д���У�
        previous = current;
        current = current->next;
    }
}

//3. �鿴�����嵥��
void displayList() {
    struct ShoppingItem* current = shoppingList;
    printf("�����嵥:\n");
    while (current != NULL) {
        printf("%s - ������%d\n", current->name, current->quantity);
        //�˴���дһ�䣻
        current = current->next;
    }
}

//4. �޸Ĺ����嵥����Ʒ��������
void updateQuantity(char itemName[], int newItemQuantity) {
    struct ShoppingItem* current = shoppingList;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            //�˴���дһ�䡣
            current->quantity = newItemQuantity;
            break;
        }
        current = current->next;
    }
}

//5. ��չ����嵥��
void clearList() {
    while (shoppingList != NULL) {
        //�˴���д���䡣
        struct ShoppingItem* temp = shoppingList;
        shoppingList = shoppingList->next;
        free(temp);
    }
}

//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
    struct ShoppingItem* current = shoppingList;
    int total = 0;
    while (current != NULL) {
        //�˴���д���䣻
        total += current->quantity;
        current = current->next;
    }
    return total;
}

//7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    printf("������Ʒ \"%s\" ��\n", itemName);
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            printf("%s - ������%d\n", current->name, current->quantity);
            return;
        }
        //�˴���дһ�䡣
        current = current->next;
    }
    printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}

//8. �������嵥��
void sortList() {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* nextItem = NULL;
    char tempName[50];
    int tempQuantity;
    while (current != NULL) {
        nextItem = current->next;
        while (nextItem != NULL) {
            if (strcmp(current->name, nextItem->name) > 0) {
                //������Ʒ��Ϣ
                //�˴���д 3 �䣻
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

//9. �ϲ������嵥��
//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
    struct ShoppingItem* current = *list1;
    // ��������һ�������嵥��ĩβ
    //����ѭ����䣻
    while (current != NULL && current->next != NULL)
        current = current->next;
    // ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
    current->next = *list2;
    *list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}

//10. ɾ�������嵥�е���Ʒ��
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ��
//����ѡ��ɾ������һ����ȫ����
void deleteItem(char itemName[], int deleteAll) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (prev == NULL) {
                // ���Ҫɾ�����ǵ�һ���ڵ�
                struct ShoppingItem* temp = shoppingList;
                //��дһ�䣻
                shoppingList = shoppingList->next;
                free(temp);
                if (!deleteAll) break;
            }
            else {
                // ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
                //��дһ�䣻
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
    //1. �����Ʒ�������嵥��
    //3. �鿴�����嵥��
    printf("�����Ʒ�������嵥��\n");

    addItem("��Ʒ1", 1);
    addItem("��Ʒ2", 2);
    addItem("��Ʒ3", 3);
    addItem("��Ʒ4", 4);
    addItem("��Ʒ5", 5);
    addItem("��Ʒ6", 6);
    displayList();
    //4. �޸Ĺ����嵥����Ʒ��������
    //3. �鿴�����嵥��
    printf("\n�޸Ĺ����嵥����Ʒ��������\n");
    updateQuantity("��Ʒ6", 10);
    displayList();

    //6. ���㹺���嵥����Ʒ����������
    printf("\n���㹺���嵥����Ʒ����������\n%d\n", totalQuantity());

    //7. ���ҹ����嵥�е���Ʒ��
    printf("\n���ҹ����嵥�е���Ʒ��\n");
    findItem("��Ʒ5");

    //8. �������嵥��
    //3. �鿴�����嵥��
    printf("\n�������嵥��\n");
    sortList();
    displayList();

    //9. �ϲ������嵥��//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
    //3. �鿴�����嵥��
    printf("\n�ϲ������嵥��\n");
    addItem1("��Ʒ3", 3);
    addItem1("��Ʒ4", 4);
    mergeLists(&shoppingList, &shoppingList1);
    displayList();

    //2. �ӹ����嵥���Ƴ���Ʒ��
    //3. �鿴�����嵥��
    printf("\n�ӹ����嵥���Ƴ���Ʒ��\n");
    removeItem("��Ʒ2");
    displayList();

    //10. ɾ�������嵥�е���Ʒ��//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ��//����ѡ��ɾ������һ����ȫ����
    //3. �鿴�����嵥��
    printf("\nɾ�������嵥�е���Ʒ��\n");
    deleteItem("��Ʒ3", 0);
    deleteItem("��Ʒ4", 1);
    displayList();

    //5. ��չ����嵥��
    //3. �鿴�����嵥��
    printf("\n��չ����嵥��\n");
    clearList();
    displayList();
    return 0;
}