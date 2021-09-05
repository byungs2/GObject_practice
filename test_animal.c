#include "test_animal.h"

enum {
	TEST_ANIMAL_PROP_0,
	TEST_ANIMAL_PROP_NUMBER_OF_LEGS
};

typedef struct _TestAnimalPrivate TestAnimalPrivate;

struct _TestAnimalPrivate {
	gchar *name;
	gint age;
	gint number_of_legs;
};

#define TEST_ANIMAL_GET_PRIVATE(animal) G_TYPE_INSTANCE_GET_PRIVATE (animal, TEST_TYPE_ANIMAL, TestAnimalPrivate)

G_DEFINE_TYPE(TestAnimal, test_animal, G_TYPE_OBJECT)
	
static void test_animal_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec){
	g_print("Get property from element\n");
	TestAnimal *animal = TEST_ANIMAL (object);
	TestAnimalPrivate *priv = TEST_ANIMAL_GET_PRIVATE (animal);
	switch (property_id){
		case TEST_ANIMAL_PROP_NUMBER_OF_LEGS:
			g_value_set_int (value, priv->number_of_legs);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
			break;
	}
}

static void test_animal_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec){
	g_print("Set property from element \n");
	TestAnimal *animal = TEST_ANIMAL (object);
	TestAnimalPrivate *priv = TEST_ANIMAL_GET_PRIVATE (animal);
	switch (property_id) {
		case TEST_ANIMAL_PROP_NUMBER_OF_LEGS:
			priv->number_of_legs = g_value_get_int(value);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
			break;
	}
}

static void test_animal_dispose (GObject *gobject) {
	TestAnimal *animal = TEST_ANIMAL (gobject);
	TestAnimalPrivate *priv;
	priv = TEST_ANIMAL_GET_PRIVATE(animal); 

	//g_clear_object (&priv->something);
	G_OBJECT_CLASS (test_animal_parent_class)->dispose(gobject);
}

static void test_animal_finalize (GObject *gobject) {
	TestAnimal *animal = TEST_ANIMAL (gobject);
	TestAnimalPrivate *priv;
	priv = TEST_ANIMAL_GET_PRIVATE(animal);

	g_free (priv->name);

	G_OBJECT_CLASS (test_animal_parent_class)->finalize (gobject);
}

void test_animal_real_make_sound (TestAnimal *self);

void test_animal_real_move (TestAnimal *self, gint x, gint y);

TestAnimal* test_animal_new () {
	// Should set default value of property at here
	return g_object_new (TEST_TYPE_ANIMAL, "number_of_legs", 10, NULL);
}

static void test_animal_init (TestAnimal *animal) {
	TestAnimalPrivate *priv;
	priv = TEST_ANIMAL_GET_PRIVATE(animal);
	priv->name = g_strdup("");
	priv->age = 0;
}

static void test_animal_class_init (TestAnimalClass *klass) {
	GObjectClass *parent_class = G_OBJECT_CLASS (klass);
	GParamSpec *pspec;

	klass->make_sound = test_animal_real_make_sound;
	klass->move = test_animal_real_move;

	parent_class->dispose = test_animal_dispose;
	parent_class->finalize = test_animal_finalize;
	parent_class->set_property = test_animal_set_property;
	parent_class->get_property = test_animal_get_property;

	g_type_class_add_private (parent_class, sizeof (TestAnimalPrivate));

	pspec = g_param_spec_int ("number_of_legs",
			"Number_of_legs",
			"the number of legs",
			10,
			50,
			10,
			G_PARAM_READWRITE);
	g_object_class_install_property (parent_class, TEST_ANIMAL_PROP_NUMBER_OF_LEGS, pspec);
}

void test_animal_make_sound (TestAnimal *self) {
	g_return_if_fail (TEST_IS_ANIMAL (self));
	
	TestAnimalClass *klass = TEST_ANIMAL_GET_CLASS (self);
	klass->make_sound (self);
}

void test_animal_move (TestAnimal *self, gint x, gint y) {
	g_return_if_fail (TEST_IS_ANIMAL (self));
	
	TestAnimalClass *klass = TEST_ANIMAL_GET_CLASS (self);
	klass->move (self, x, y);
}

gchar* test_animal_get_name (TestAnimal *self) {
	g_return_val_if_fail (TEST_IS_ANIMAL (self), NULL);

	TestAnimalPrivate *priv = TEST_ANIMAL_GET_PRIVATE (self);
	g_print("Get name of mother of animals\n");
	return g_strdup (priv->name);
}

void test_animal_set_name (TestAnimal *self, gchar *name) { 
	g_return_if_fail (TEST_IS_ANIMAL (self));
	TestAnimalPrivate *priv = TEST_ANIMAL_GET_PRIVATE(self);
	
	g_free (priv->name);
	priv->name = g_strdup (name);
	g_print("Set name of mother of animals %s\n", name);
}

gint test_animal_get_age (TestAnimal *self) {
	g_return_val_if_fail (TEST_IS_ANIMAL (self), NULL);
	TestAnimalPrivate *priv = TEST_ANIMAL_GET_PRIVATE(self);
	g_print("Get age of animal\n");
	return priv->age;
}

void test_animal_set_age (TestAnimal *self, gint age) {
	g_return_if_fail (TEST_IS_ANIMAL (self));
	TestAnimalPrivate *priv = TEST_ANIMAL_GET_PRIVATE(self);
	g_print("Set age of animal %d\n", age); 
	priv->age = age;
}

void test_animal_real_make_sound (TestAnimal *self) {
	g_print("Wolf \n"); 
}
void test_animal_real_move (TestAnimal *self, gint x, gint y) {
	g_print("Move %d %d \n", x, y);
}

