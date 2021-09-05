#include "test_animal.h"
#include "cat.h"

int main (int argc, char **argv) {
	TestAnimal *a = test_animal_new ();
	TestCat *cat = test_cat_new ();

	test_animal_set_name (a, "Mother of animals");
	g_print("%s\n", test_animal_get_name (a));

	test_animal_make_sound(a);
	test_animal_move(a, 5, 6);

	test_animal_make_sound(TEST_ANIMAL(cat));
	test_animal_move (TEST_ANIMAL(cat), 3, 8);

	//g_object_set(a, "number_of_legs", 6, NULL);
	//g_print("Set done \n");
  gint num_legs;
	GParamSpec *pspec = g_object_class_find_property (G_OBJECT_GET_CLASS (a), "number_of_legs");
	GValue *value = g_param_spec_get_default_value(pspec);
	num_legs = g_value_get_int(value);
	g_print("Number of legs : %d \n", num_legs);
	g_object_get(a, "number_of_legs", &num_legs, NULL);
	g_print("Number of legs : %d \n", num_legs);

	g_object_unref (a);
	return 0;
}
