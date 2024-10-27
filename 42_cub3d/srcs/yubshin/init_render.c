#include "../../cub3d.h"

void	cal_plane(t_view *view)
{
	double		dir_length; // 플레이어 방향 벡터의 길이
	t_pair_dbl	norm_dir; // 정규화된 방향 벡터

	// 방향 벡터의 길이 계산
	dir_length = sqrt(view->dir.x * view->dir.x + view->dir.y * view->dir.y);
	if (dir_length > 0)
	{
		// 방향 벡터를 길이로 나누어 정규화
		norm_dir.x = view->dir.x / dir_length;
		norm_dir.y = view->dir.y / dir_length;

		// 정규화된 방향 벡터에 수직인 평면 벡터를 생성
		view->plane.x = -norm_dir.y * 0.88; // 방향 벡터에 수직 방향의 X 좌표
		view->plane.y = norm_dir.x * 0.88;  // 방향 벡터에 수직 방향의 Y 좌표
	}
	else // 방향이 없을 경우 평면 벡터를 (0, 0)으로 설정
	{
		view->plane.x = 0;
		view->plane.y = 0;
	}
}

void	init_render(t_rnd *rnd, t_player player)
{
	// 플레이어 위치와 방향 정보를 rnd 구조체의 view에 설정
	rnd->view.pos.x = player.pos.x;
	rnd->view.pos.y = player.pos.y;
	rnd->view.dir.x = player.dir.x;
	rnd->view.dir.y = player.dir.y;
	// 평면 벡터 계산을 통해 플레이어의 시야 설정
	cal_plane(&rnd->view);
}
