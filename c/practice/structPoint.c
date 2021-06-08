// 点结构
struct point
{
    int x;
    int y;
};  

// 矩形结构（对角线上的两点）
struct rect
{
    struct point pt1;
    struct point pt2;
};

// 创建点
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

// 判断一个点是否在矩形中（约定：矩形包括左侧边和底边，不包括右侧边和顶边）
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

// 创建一个规范（约定：pt1 的坐标小于 pt2 的坐标）矩形
#define min(a, b) (a < b? a: b)
#define max(a, b) (a > b? a: b)

struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}
