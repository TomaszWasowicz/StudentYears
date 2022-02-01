/** Implementacja drzewa binarych poszukiwañ
 *  AHE modu³ #4 ANSI C
 */
#include <stdio.h>
#include <stdlib.h>


/** Podstawowa struktura definiuj¹ca wêze³ drzewa
 * data - przechowuje dane do porównania
 * left - wskaŸnik do lewego dziecka drzewa
 * right - wskaŸnik do prawego dziecka drzewa
 */
typedef struct node_s
{
    int data;
    struct node_s* left;
    struct node_s* right;
} node;

/** Funkcja tworzy pusty wêze³ alokuj¹c pamiêæ na stosie
	inicjalizuj¹c dane przekazane jako argument data
	wskaŸnik na lewe i prawe dziecko ustawia na NULL (pusty)
*/
node* create_node(int data)
{
	// Zaalokuj pamiêæ na strukturê na stercie
    node *new_node = (node*)malloc(sizeof(node));
	// Jeœli nie mo¿na zaalokowaæ pamiêci to zwróæ NULL
    if(new_node == NULL)
    {
		return NULL;
    }
	// Wype³nij pole dana wartoœcia przekazan¹ jako argument
    new_node->data = data;
	// Ustaw lewe i prawe dziecko jako puste
    new_node->left = NULL;
    new_node->right = NULL;
	// Zwróæ wskaŸnik na utworzony element
    return new_node;
}

/** Funkcja porównuje dwie liczby ca³kowite
	jeœli paramer left jest wiêkszy od right zwraca wartoœæ dodatni¹
    jeœli parametre left jest mniejszy od right zwraca wartoœæ ujemn¹
    jeœli oba elementy s¹ takie same zwraca wartoœc równ¹ 0
*/
int compare(int left,int right)
{
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0;
}

/** Funkcja wstawia nowy element do drzewa binarnych poszukiwañ wstawiaj¹c
    go na odpowiednie miejsce zgodnie z definicj¹ i regu³ami drzewa BST
    jako argument pierwszy root przyjmuje wskaŸnik do korzenia, natomiast jako
    argument drugi przyjmuje wartosæ jak¹ chcemy wstawiæ.
	Jeœli drzewo binarne jest puste wystarczy utworzyæ nowy element, natomiast
    w przeciwnym wypadku rozpoczynamy od wêz³a g³ównego.
    Znajdujemy w³aœciw¹ pozycjê dla nowego wêz³a porównuj¹c klucz nowego
    wêz³a z kluczem wêz³a g³ównego. Jeœli klucz nowego wêz³a jest mniejszy
	ni¿ klucz wêz³a g³ównego, przechodzimy do lewego poddrzewa. Jeœli klucz
	nowego wêz³a jest wiêkszy ni¿ klucz wêz³a g³ównego, przechodzimy do prawego poddrzewa.
	Robimy ten krok rekurencyjnie, a¿ znajdziemy poprawn¹ pozycjê w drzewie,
	aby wstawiæ nowy wêze³.
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

/** Funkcja usuwa dany wêze³ z drzewa jako argument root przyjmuje
	wskaŸnik do korzenia drzewa natomiast jako argument data przyjmuje
	wartoœæ w drzewie jak¹ chcemy usun¹æ.
	Usuniêcie istniej¹cego wêz³a w drzewie wyszukiwania binarnego jest nieco
	bardziej skomplikowane. Mamy trzy przypadki, które powinniœmy wzi¹æ pod uwagê:
	Przypadek 1. Dla wêz³a nie zawiaraj¹cego liœci, czyli
	Wêze³, który nie ma elementów podrzêdnych, mo¿emy go zwyczajnie usun¹æ bez
    ¿adnych konsekwencji dla struktry drzewa.
	Przypadek 2. Jesli chcemy usun¹æ wêze³, który ma jeden wêze³ potomny,
	zamieniamy go z wêz³em potomnym a nastêpnie usuwamy.
	Przypadek 3 (Najtrudniejszy). Aby usun¹æ wêze³, który ma dwa wêz³y potomne,,
	znajdujemy jego nastêpny wêze³, który jest nastêpnym wêz³em w kolejnoœci
	uporz¹dkowania drzewa i zastêpujemy go wêz³em o odpowiadaj¹cej kolejnoœci.
*/

node* delete_node(node* root, int data)
{
	//Jeœli korzeñ nie ustawiony to koñcz z b³êdem
    if(root == NULL)
        return NULL;
    node *curr_node;
	// Porównaj zawartoœæ wêz³a z wartoœci¹ do usuniêcia
    int r = compare(data,root->data);
	//Jeœli mniejszy przejdz rekursywnie do lewego poddrzewa
    if( r < 0)
        root->left = delete_node( root->left, data);
	// Jeœli wiêkszy przejdz rekursywnie do prawego poddrzewa
    else if( r > 0 )
        root->right = delete_node(root->right,data);
	// Jeœli równy oznacza to ¿e znaleziono odpowiedni element do usuniêcia
    else
    {
		// Jeœli tylko lewe dziecko
        if (root->left == NULL)
        {
			// Usuñ ten wêze³ i przepisz wartoœæ
			// Oraz zwolnij pamiêæ zajmowan¹ przez wêze³
            curr_node = root->right;
            free(root);
            root = curr_node;
        }
		// Jeœli tylko prawe dziecko
        else if (root->right == NULL)
        {
			// Usuñ ten wêze³ i przepisz wartoœæ oraz zwolnij pamiêæ
			// zajmowan¹ przez wêze³
            curr_node = root->left;
            free(root);
            root = curr_node;
        }
        else    //Jeœli istnieje prawy oraz lewy podwêze³
        {
            curr_node = root->right;
            node *parent = NULL;
			//Przejdz do ostatniego wêz³a lewego poddrzewa
            while(curr_node->left != NULL)
            {
                parent = curr_node;
                curr_node = curr_node->left;
            }
			// Przepisz wartoœæ z tego wêz³a
            root->data = curr_node->data;
			// Wywo³aj rekurencyjnie usuniêcie prawego lub lewego podddrzewa
            if (parent != NULL)
                parent->left = delete_node(parent->left, parent->left->data);
            else
                root->right = delete_node(root->right, root->right->data);
        }
    }
    return root;
}

/** Szukaj elementu zawieraj¹cego dan¹ wartoœæ
 *  Jako parametr root podajemy korzeñ drzewa
 *  Jako parametr data podajemy wartoœæ jak¹ chcemy wyszukaæ
 *  zwraca wartoœc znalezionego wêz³a
 *  Aby wyszukaæ okreœlony klucz w drzewie wyszukiwania binarnego,
 *  rozpoczynamy od wêz³a g³ównego. Jeœli drzewo jest puste, klucz nie istnieje.
 *  W przeciwnym przypadku, jeœli klucz wêz³a g³ównego jest równy elementowi szukanemu,
 *  wyszukiwanie zakoñczy siê pomyœlnie, koñczymy wyszukiwanie.
 *  Jeœli klucz jest mniejszy ni¿ klucz wêz³a g³ównego, przeszukujemy lewe poddrzewo
 *  Podobnie, jeœli klucz jest wiêkszy ni¿ klucz wêz³a g³ównego, przeszukujemy
 *  prawe poddrzewo. Powtarzamy ten krok rekurencyjnie, a¿ klucz
 *  zostanie znaleziony lub poddrzewo ma wartoœæ NULL.
 */
node* search(node *root,const int data)
{
	// Cwiczenie 4:  Uzupe³nij kod wyszukuj¹cy zadany element w drzewie BST

    if (root == NULL || root->data == data)
       {return root;}

    if (root->data < data)
       {return search(root->right, data);}

    return search(root->left, data);


}


/** Wyœwietla drzewo na ekranie
 * jako argument przyjmuje wskaŸnik do wêz³a
 * Funkcja przchodzi przez ca³e poddrzewo i wywo³uje siebie rekurencyjnie
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

/** Usuwa ca³¹ zawartoœæ drzewa.
 * Aby usun¹æ drzewo nale¿y przejœc od korzenia do koñca drzewa
 * oraz usun¹æ wszystkie elementy tego drzewa.
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
	//Dodajemy przyk³adowe elementy do drzewa binarnego
	root = insert_node(root,8);
	root = insert_node(root,3);
	root = insert_node(root,10);
	root = insert_node(root,1);
	root = insert_node(root,6);
	root = insert_node(root,14);
	root = insert_node(root,4);
	root = insert_node(root,7);
	root = insert_node(root,13);
	//Wyœwietlamy zawartoœæ drzewa binarnego
	display_tree(root);
	//Wyszukaj zadany element w drzewie binarnym
	for( int key=0;; )
	{
		node* s;
		printf("Podaj wartosc klucza do wyszukania. Wpisz -1 aby zakonczyæ: ");
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
		printf("Podaj wartosc klucza do usuniecia. Wpisz -1 aby zakonczyæ: ");
        scanf("%d",&key);
		if( key < 0 ) break;
		root = delete_node(root,key);
        /* display the tree */
        if(root != NULL) display_tree(root);
        else break;
	}
	// Usuwanie wszystkich elementów i wyœwietlenie
	remove_all(&root);
	if( root )
		display_tree(root);
	else
		printf("Drzewo puste\n");
	return 0;
}

