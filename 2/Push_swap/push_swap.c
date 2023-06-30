/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:48 by spark2            #+#    #+#             */
/*   Updated: 2023/06/30 21:05:09 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**new_arv;
int		print_max = 0;
void    check_list(t_stack *stacks, t_list *a_head)//check list
{
	if (print_max == 300)
		return ;//exit(1);
	print_max++;
	printf("print_max_idx: %d\n", print_max);
    t_list *cura;
    t_list *curb;
    char **origin_arv = new_arv;
    if (stacks != NULL){
        cura = stacks->a_head;
        //curb = stacks->b_head;
    }
        else{
            cura = a_head;
            //curb = NULL;
        }
    int i = 0, j = 0;
    // while (origin_arv[i])
    // {
    //     j = 0;
    //     while (origin_arv[i][j])
    //     {
    //         printf("%c", origin_arv[i][j]);
    //         j++;
    //     }
    //     printf(" ");
    //     i++;
    // }
    printf("\n");
    int    cnt = 1;
    printf("============\t============\n");
    while (cura != NULL /*|| curb != NULL*/)
    {
        if (cura != NULL)
        {
            printf("A_ %d: %d", cnt, cura->content);
            cura = cura->next;
        }
        printf("\t\t");
        // if (curb != NULL)
        // {
        //     printf("B_ %d: %d", cnt, curb->content);
        //     curb = curb->next;
        // }
        printf("\n");
        cnt++;
    }
    printf("============\t============\n\n");
}

void	ps_init(t_stack *stacks, int *argc, char **argv)
{
	int		i;
	int		j;
	int		argc_org;
	t_list	*head;
	t_list	*new;

	if (*argc <= 1)
		return ;
	i = 0;
	argc_org = *argc;
	while (++i < argc_org)
	{
		argv = ft_split(argv, argc);
		if (!argv)
			return ;
		j = ft_atoi(argv[i - 1]); //long 처리 필요
		printf("%d\n", j);
		if (i == 1)
			head = ft_lstnew(j);
		else
		{
			new = ft_lstnew(j);
			head->next = new;
			//printf("new->content: %d\n", new->content);
			// printf("new->next: %p\n", new->next);
			// printf("===================\n");
		}
		// printf("atoi한 값: %d\n", j);
		// printf("head->content: %d\n", head->content);
		// printf("head->next: %p\n", head->next);
		// printf("argc: %d\n", argc);
		// printf("%s\n", argv[1]);
	}
	stacks->a_head = head;
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	ps_init(&stacks, &argc, argv);
	//check_list(&stacks, stacks.a_head);
	//1. atoi로 받아온 인자 바꾸기 - 4 3 1 " 8 7"로 들어오면 뒤에 split해서 각각 인자값 받기
	//2. 스택에 바로 넣기 (연결리스트로 구성됨) - 중복 인자 체크
	// while (++i < argc)
	// {
	// 	printf("%d\n", new->content);
	// }
}