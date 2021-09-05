#ifndef __TEST_ANIMAL_H__
#define __TEST_ANIMAL_H__
#include <glib-object.h>
#include <glib.h>

//After g-lib 2.44
//G_DECLARE_DERIVABLE_TYPE (TestAnimal, test_animal, TEST, ANIMAL, GObject)

G_BEGIN_DECLS
#define TEST_TYPE_ANIMAL (test_animal_get_type ())
#define TEST_ANIMAL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TEST_TYPE_ANIMAL, TestAnimal))
#define TEST_IS_ANIMAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), TEST_TYPE_ANIMAL))
#define TEST_ANIMAL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TEST_TYPE_ANIMAL, TestAnimalClass))
#define TEST_IS_ANIMAL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TEST_TYPE_ANIMAL))
#define TEST_ANIMAL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TEST_TYPE_ANIMAL, TestAnimalClass))

typedef struct _TestAnimal TestAnimal;

typedef struct _TestAnimalClass TestAnimalClass;

struct _TestAnimal {
	GObject parent_class_instance;
};

struct _TestAnimalClass {
	GObjectClass parent_class;
	
	void (* make_sound)(TestAnimal *);
	
	void (* move) (TestAnimal *, gint x, gint y);

	gpointer padding[12];
};

GType test_animal_get_type (void) G_GNUC_CONST;

TestAnimal* test_animal_new ();

void test_animal_make_sound (TestAnimal *self);

void test_animal_move (TestAnimal *self, gint x, gint y);

gchar* test_animal_get_name (TestAnimal *self);

void test_animal_set_name (TestAnimal *self, gchar *name);

gint test_animal_get_age (TestAnimal *self);

void test_animal_set_age (TestAnimal *self, gint age);

G_END_DECLS
#endif
