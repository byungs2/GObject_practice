#ifndef __TEST_CAT_H__
#define __TEST_CAT_H__
#include "test_animal.h"

//After g-lib 2.44 
//G_DECLARE_FINAL_TYPE (TestCat, test_cat, TEST, CAT, TestAnimal)

G_BEGIN_DECLS

#define TEST_TYPE_CAT test_cat_get_type()
#define TEST_CAT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TEST_TYPE_CAT, TestCat))
#define TEST_IS_CAT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), TEST_TYPE_CAT))
#define TEST_CAT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TEST_TYPE_CAT, TestCatClass))
#define TEST_IS_CAT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TEST_TYPE_CAT))
#define TEST_CAT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TEST_TYPE_CAT, TestCatClass))

typedef struct _TestCat TestCat;
typedef struct _TestCatClass TestCatClass;

GType test_cat_get_type (void) G_GNUC_CONST;
TestCat* test_cat_new();

G_END_DECLS

#endif
