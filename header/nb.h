#ifndef NB_H
#define NB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "boolean.h"

#define jml_maks 100
#define nil 0

typedef char infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbnode;

typedef nbnode Isi_Tree[jml_maks+1];

void Create_tree(Isi_Tree t, int Jml_Node);
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);
int Max(infotype Data1, infotype Data2);
void PreOrder(Isi_Tree P);
void InOrder(Isi_Tree P);
void PostOrder(Isi_Tree P);
void Level_order(Isi_Tree X, int Maks_node);
void PrintTree(Isi_Tree P);
boolean Search(Isi_Tree P, infotype X);
boolean IsEmpty(Isi_Tree P);

#define jml_maks_morse 100
#define nil_morse 0

typedef char infotype_morse;
typedef int address_morse;

typedef struct {
    infotype_morse info;
    address_morse left, right;
} nbtree_morse;

typedef nbtree_morse Isi_Tree_Morse[jml_maks_morse+1];

void inisialize(Isi_Tree_Morse tree);
void add_morse(Isi_Tree_Morse tree);
void InorderTranversal(Isi_Tree_Morse tree, address_morse root);
void ConvertString(Isi_Tree_Morse tree, const char* input, const char* outputFile);
void ConvertFile(Isi_Tree_Morse tree, const char* inputFile, const char* outputFile);

#endif
