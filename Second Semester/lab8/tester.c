#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *down;
};

struct Node* createNode(int x);
void appendNode(struct Node** h, int x);
void linkLists(struct Node* u, struct Node* d);

static void test_createNode(void **state) {
    struct Node* a = createNode(5);
    assert_non_null(a);
    assert_int_equal(a->data, 5);
    assert_null(a->next);
    assert_null(a->down);
    free(a);
}

static void test_appendNode(void **state) {
    struct Node* h = 0;
    appendNode(&h, 1);
    appendNode(&h, 2);
    appendNode(&h, 3);
    assert_int_equal(h->data, 1);
    assert_int_equal(h->next->data, 2);
    assert_int_equal(h->next->next->data, 3);
    assert_null(h->next->next->next);

    struct Node* tmp;
    while (h) {
        tmp = h;
        h = h->next;
        free(tmp);
    }
}

static void test_linkLists(void **state) {
    struct Node *u = 0, *d = 0;
    appendNode(&u, 7);
    appendNode(&u, 8);
    appendNode(&d, 9);
    appendNode(&d, 10);
    linkLists(u, d);

    assert_int_equal(u->down->data, 9);
    assert_int_equal(u->next->down->data, 10);

    struct Node *t;
    while (u) {
        t = u;
        u = u->next;
        free(t->down);
        free(t);
    }
}

int main(void) {
    const struct CMUnitTest t[] = {
        cmocka_unit_test(test_createNode),
        cmocka_unit_test(test_appendNode),
        cmocka_unit_test(test_linkLists),
    };
    return cmocka_run_group_tests(t, 0, 0);
}
