1) 

(a)
int list_erase_even(List *li)
{
  if (li == NULL)
    return -1;

  int cont = 1;
  No *aux = li->begin;
  No *aux2;
  while (aux != NULL)
  {
    if (aux->data % 2 ==0)
    {
      aux2 = aux;   
      aux->prev->next = aux2->next; //cuidado pois o nó pode ser o primeiro ou o último
      aux->next->prev = aux2->prev;
      free(aux2);
      li->size -= 1;
      
    }
    cont++;
    aux = aux->next;
  }
  return 0;
  
}
(b)

vou mandar imagens da B









(c)
int list_splice(List *li, List *li2, int pos)
{
   if (li == NULL)
    return -1;

  int cont = 1;
  No *aux = li->begin;
  No *aux3 = li2->begin;
  No *aux2;

  if(li->size=0)
  {
	li=li2; //não pode fazer isso
	return 0;
  }
  if(li2->size=0)
  {
	return 0;
  }
  
  while (aux != NULL) // veja bem esse loop.. com um if que só aparece uma vez.. 
  {
    if (pos == cont)
    {
      aux2 = aux;
      aux->prev->next = aux3;
      aux3->prev= aux2->prev;
      
      li2->end->next = aux2;
      aux2->prev = li2->end;
      if(pos == li->size)
      {
        li->end = li2->end;
      }
      
      li->size += li2->size;
      
      li2->begin =li2->end = NULL;
      li2->size =0;
      return 0;
    }
    cont++;
    aux = aux->next;
  }

  return -1;

}

