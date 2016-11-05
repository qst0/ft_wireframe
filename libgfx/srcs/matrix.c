/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:25:54 by myoung            #+#    #+#             */
/*   Updated: 2016/10/30 21:24:54 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void	mat_bzero(float mat[4][4])
{
	ft_bzero(mat[0], sizeof(float) * 4);
	ft_bzero(mat[1], sizeof(float) * 4);
	ft_bzero(mat[2], sizeof(float) * 4);
	ft_bzero(mat[3], sizeof(float) * 4);
}

void	get_id_matrix(float mat[4][4])
{
	mat_bzero(mat);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void	mat_mult(float m1[4][4], float m2[4][4], float dst[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dst[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
	}
}

void	mat_translate(float mat[4][4], float x, float y, float z)
{
	float	tran_mat[4][4];

	get_id_matrix(tran_mat);
	tran_mat[3][0] = x;
	tran_mat[3][1] = y;
	tran_mat[3][2] = z;
	mat_mult(mat, tran_mat, mat);
}

void	mat_scale(float mat[4][4], float x, float y, float z)
{
	float	scale_mat[4][4];

	mat_bzero(scale_mat);
	scale_mat[0][0] = x;
	scale_mat[1][1] = y;
	scale_mat[2][2] = z;
	scale_mat[3][3] = 1;
	mat_mult(mat, scale_mat, mat);
}
