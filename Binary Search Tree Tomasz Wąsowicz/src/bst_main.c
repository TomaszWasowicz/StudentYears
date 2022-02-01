/** Implementacja drzewa binarych poszukiwa�
 *  AHE modu� #4 ANSI C
 */
#include <stdio.h>
#include <stdlib.h>


/** Podstawowa struktura definiuj�ca w�ze� drzewa
 * data - przechowuje dane do por�wnania
 * left - wska�nik do lewego dziecka drzewa
 * right - wska�nik do prawego dziecka drzewa
 */
typedef struct node_s
{
    int data;
    struct node_s* left;
    struct node_s* right;
} node;

/** Funkcja tworzy pusty w�ze� alokuj�c pami�� na stosie
	inicjalizuj�c dane przekazane jako argument data
	wska�nik na lewe i prawe dziecko ustawia na NULL (pusty)
*/
node* create_node(int data)
{
	// Zaalokuj pami�� na struktur� na stercie
    node *new_node = (node*)malloc(sizeof(node));
	// Je�li nie mo�na zaalokowa� pami�ci to zwr�� NULL
    if(new_node == NULL)
    {
		return NULL;
    }
	// Wype�nij pole dana warto�cia przekazan� jako argument
    new_node->data = data;
	// Ustaw lewe i prawe dziecko jako puste
    new_node->left = NULL;
    new_node->right = NULL;
	// Zwr�� wska�nik na utworzony element
    return new_node;
}

/** Funkcja por�wnuje dwie liczby ca�kowite
	je�li paramer left jest wi�kszy od right zwraca warto�� dodatni�
    je�li parametre left jest mniejszy od right zwraca warto�� ujemn�
    je�li oba elementy s� takie same zwraca warto�c r�wn� 0
*/
int compare(int left,int right)
{
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0;
}

/** Funkcja wstawia nowy element do drzewa binarnych poszukiwa� wstawiaj�c
    go na odpowiednie miejsce zgodnie z definicj� i regu�ami drzewa BST
    jako argument pierwszy root przyjmuje wska�nik do korzenia, natomiast jako
    argument drugi przyjmuje wartos� jak� chcemy wstawi�.
	Je�li drzewo binarne jest puste wystarczy utworzy� nowy element, natomiast
    w przeciwnym wypadku rozpoczynamy od w�z�a g��wnego.
    Znajdujemy w�a�ciw� pozycj� dla nowego w�z�a por�wnuj�c klucz nowego
    w�z�a z kluczem w�z�a g��wnego. Je�li klucz nowego w�z�a jest mniejszy
	ni� klucz w�z�a g��wnego, przechodzimy do lewego poddrzewa. Je�li klucz
	nowego w�z�a jest wi�kszy ni� klucz w�z�a g��wnego, przechodzimy do prawego poddrzewa.
	Robimy ten krok rekurencyjnie, a� znajdziemy poprawn� pozycj� w drzewie,
	aby wstawi� nowy w�ze�.
*/

node* insert_node(node *root, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
    }
    else
    {
        int is_left  = 0;
        int r        = 0;
        node* curr_node = root;
        node* prev_node   = NULL;
        while(curr_node)
        {
            r = compare(data,curr_node->data);
            prev_node = curr_node;
            if(r < 0)
            {
                is_left = 1;
                curr_node = curr_node->left;
            }
            else if(r > 0)
            {
                is_left = 0;
                curr_node = curr_node->right;
            }
        }
        if(is_left)
            prev_node->left = create_node(data);
        else
            prev_node->right = create_node(data);
    }
    return root;
}

/** Funkcja usuwa dany w�ze� z drzewa jako argument root przyjmuje
	wska�nik do korzenia drzewa natomiast jako argument data przyjmuje
	warto�� w drzewie jak� chcemy usun��.
	Usuni�cie istniej�cego w�z�a w drzewie wyszukiwania binarnego jest nieco
	bardziej skomplikowane. Mamy trzy przypadki, kt�re powinni�my wzi�� pod uwag�:
	Przypadek 1. Dla w�z�a nie zawiaraj�cego li�ci, czyli
	W�ze�, kt�ry nie ma element�w podrz�dnych, mo�emy go zwyczajnie usun�� bez
    �adnych konsekwencji dla struktry drzewa.
	Przypadek 2. Jesli chcemy usun�� w�ze�, kt�ry ma jeden w�ze� potomny,
	zamieniamy go z w�z�em potomnym a nast�pnie usuwamy.
	Przypadek 3 (Najtrudniejszy). Aby usun�� w�ze�, kt�ry ma dwa w�z�y potomne,,
	znajdujemy jego nast�pny w�ze�, kt�ry jest nast�pnym w�z�em w kolejno�ci
	uporz�dkowania drzewa i zast�pujemy go w�z�em o odpowiadaj�cej kolejno�ci.
*/

node* delete_node(node* root, int data)
{
	//Je�li korze� nie ustawiony to ko�cz z b��dem
    if(root == NULL)
        return NULL;
    node *curr_node;
	// Por�wnaj zawarto�� w�z�a z warto�ci� do usuni�cia
    int r = compare(data,root->data);
	//Je�li mniejszy przejdz rekursywnie do lewego poddrzewa
    if( r < 0)
        root->left = delete_node( root->left, data);
	// Je�li wi�kszy przejdz rekursywnie do prawego poddrzewa
    else if( r > 0 )
        root->right = delete_node(root->right,data);
	// Je�li r�wny oznacza to �e znaleziono odpowiedni element do usuni�cia
    else
    {
		// Je�li tylko lewe dziecko
        if (root->left == NULL)
        {
			// Usu� ten w�ze� i przepisz warto��
			// Oraz zwolnij pami�� zajmowan� przez w�ze�
            curr_node = root->right;
            free(root);
            root = curr_node;
        }
		// Je�li tylko prawe dziecko
        else if (root->right == NULL)
        {
			// Usu� ten w�ze� i przepisz warto�� oraz zwolnij pami��
			// zajmowan� przez w�ze�
            curr_node = root->left;
            free(root);
            root = curr_node;
        }
        else    //Je�li istnieje prawy oraz lewy podw�ze�
        {
            curr_node = root->right;
            node *parent = NULL;
			//Przejdz do ostatniego w�z�a lewego poddrzewa
            while(curr_node->left != NULL)
            {
                parent = curr_node;
                curr_node = curr_node->left;
            }
			// Przepisz warto�� z tego w�z�a
            root->data = curr_node->data;
			// Wywo�aj rekurencyjnie usuni�cie prawego lub lewego podddrzewa
            if (parent != NULL)
                parent->left = delete_node(parent->left, parent->left->data);
            else
                root->right = delete_node(root->right, root->right->data);
        }
    }
    return root;
}

/** Szukaj elementu zawieraj�cego dan� warto��
 *  Jako parametr root podajemy korze� drzewa
 *  Jako parametr data podajemy warto�� jak� chcemy wyszuka�
 *  zwraca warto�c znalezionego w�z�a
 *  Aby wyszuka� okre�lony klucz w drzewie wyszukiwania binarnego,
 *  rozpoczynamy od w�z�a g��wnego. Je�li drzewo jest puste, klucz nie istnieje.
 *  W przeciwnym przypadku, je�li klucz w�z�a g��wnego jest r�wny elementowi szukanemu,
 *  wyszukiwanie zako�czy si� pomy�lnie, ko�czymy wyszukiwanie.
 *  Je�li klucz jest mniejszy ni� klucz w�z�a g��wnego, przeszukujemy lewe poddrzewo
 *  Podobnie, je�li klucz jest wi�kszy ni� klucz w�z�a g��wnego, przeszukujemy
 *  prawe poddrzewo. Powtarzamy ten krok rekurencyjnie, a� klucz
 *  zostanie znaleziony lub poddrzewo ma warto�� NULL.
 */
node* search(node *root,const int data)
{
	// Cwiczenie 4:  Uzupe�nij kod wyszukuj�cy zadany element w drzewie BST

    if (root == NULL || root->data == data)
       {return root;}

    if (root->data < data)
       {return search(root->right, data);}

    return search(root->left, data);


}


/** Wy�wietla drzewo na ekranie
 * jako argument przyjmuje wska�nik do w�z�a
 * Funkcja przchodzi przez ca�e poddrzewo i wywo�uje siebie rekurencyjnie
 * dla lewego ora dla prawego poddrzewa
 */
void display_tree(node* nd)
{
    if (nd == NULL)
        return;
    printf("%d",nd->data);
    if(nd->left != NULL)
        printf("(L:%d)",nd->left->data);
    if(nd->right != NULL)
        printf("(R:%d)",nd->right->data);
    printf("\n");
    display_tree(nd->left);
    display_tree(nd->right);
}

/** Usuwa ca�� zawarto�� drzewa.
 * Aby usun�� drzewo nale�y przej�c od korzenia do ko�ca drzewa
 * oraz usun�� wszystkie elementy tego drzewa.
 */

void _remove_all(node* root)
{
    node *ln;
    node *rn;

if (root->left != 0)
{ln = root->left;}
else ln = NULL;
if (root->right != 0)
{rn = root->right;}
else rn = NULL;
free(root);
root = NULL;

if (ln == 0 && rn == 0) return;

if (ln != 0) _remove_all(ln);
if (rn != 0) _remove_all(rn);


}

void remove_all( node** root)
{
	_remove_all(*root);
    *root = NULL;
}
int main(void)
{
	//Inicjalizujemy zmienne lokalne
	node* root = NULL;
	//Dodajemy przyk�adowe elementy do drzewa binarnego
	root = insert_node(root,8);
	root = insert_node(root,3);
	root = insert_node(root,10);
	root = insert_node(root,1);
	root = insert_node(root,6);
	root = insert_node(root,14);
	root = insert_node(root,4);
	root = insert_node(root,7);
	root = insert_node(root,13);
	//Wy�wietlamy zawarto�� drzewa binarnego
	display_tree(root);
	//Wyszukaj zadany element w drzewie binarnym
	for( int key=0;; )
	{
		node* s;
		printf("Podaj wartosc klucza do wyszukania. Wpisz -1 aby zakonczy�: ");
        scanf("%d",&key);
		if( key < 0 ) break;
		s = search(root,key);
        if(s != NULL)
        {
            printf("Znaleziono element %i",s->data);
            if(s->left != NULL)
                printf("(L: %i)",s->left->data);
            if(s->right != NULL)
                printf("(R: %i)",s->right->data);
            printf("\n");
        }
        else
        {
            printf("wezel %i nie zostal znaleziony\n",key);
        }
	}
	// Usuwanie danego elementu
	for( int key=0;;)
	{
		printf("Podaj wartosc klucza do usuniecia. Wpisz -1 aby zakonczy�: ");
        scanf("%d",&key);
		if( key < 0 ) break;
		root = delete_node(root,key);
        /* display the tree */
        if(root != NULL) display_tree(root);
        else break;
	}
	// Usuwanie wszystkich element�w i wy�wietlenie
	remove_all(&root);
	if( root )
		display_tree(root);
	else
		printf("Drzewo puste\n");
	return 0;
}

