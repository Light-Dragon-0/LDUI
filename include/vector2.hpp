template<typename componentT>
class vector2
{
public:
	componentT x;
	componentT y;
    vector2();
	vector2(componentT value);
    vector2(componentT x,componentT y); 
    vector2(vector2& copy);
    vector2 add(vector2& b);
    void add_eq(vector2& b);
    static vector2 add(vector2& a,vector2& b);
    vector2 operator+(vector2& b);
    void operator+=(vector2& b);
    vector2 sub(vector2& b);
    void sub_eq(vector2& b);
    static vector2 sub(vector2& a,vector2& b);
    vector2 operator-(vector2& b);
    void operator-=(vector2& b);
    vector2 mul(vector2& b);
    void mul_eq(vector2& b);
    static vector2 mul(vector2& a,vector2& b);
    vector2 operator*(vector2& b);
    void operator*=(vector2& b);
    vector2 div(vector2& b);
    void div_eq(vector2& b);
    static vector2 div(vector2& a,vector2& b);
    vector2 operator/(vector2& b);
    void operator/=(vector2& b);
    vector2 floor_c();
    void floor_c_eq();
    static vector2 floor_c(vector2& a);
    vector2 round_c();
    void round_c_eq();
    static vector2 round_c(vector2& a);
    vector2 ceil_c();
    void ceil_c_eq();
    static vector2 ceil_c(vector2& a);
    vector2 min_c(vector2& b); //returns the min of each component
    void min_c_eq(vector2& b);
    static vector2 min_c(vector2& a,vector2& b);
    vector2 min_l(vector2& b); //returns the vector with min length
    void min_l_eq(vector2& b);
    static vector2 min_l(vector2& a,vector2& b);
    vector2 max_c(vector2& b); //returns the max of each component
    void max_c_eq(vector2& b);
    static vector2 max_c(vector2& a,vector2& b);
    vector2 max_l(vector2& b); //returns the vector with max length
    void max_l_eq(vector2& b);
    static vector2 max_l(vector2& a,vector2& b);
    componentT length(vector2& b);
    void length_c_eq(vector2& b);
    void length_l_eq(vector2& b);
    static componentT length(vector2& a,vector2& b);
    componentT det();
    componentT det_c_eq();
    static componentT det(vector2& a);
    vector2 normal();
    static vector2 normal(vector2& a);
    void normalize();
    componentT dot(vector2& b);
    void dot_c_eq(vector2& b);
    static componentT dot(vector2& a,vector2& b);
    vector2 cross(vector2& b);
    vector2 cross_eq(vector2& b);
    static vector2 cross(vector2& a,vector2& b);
    void operator=(vector2& a);
    bool equals(vector2& b);
    static bool equals(vector2& a,vector2& b);
    bool any_equals(vector2& b);
    static bool any_equals(vector2& a,vector2& b);
    bool equals_l(vector2& a);
    static bool equals_l(vector2& a,vector2& b);
    vector2 add(componentT b);
    void add_eq(componentT b);
    static vector2 add(vector2& a,componentT b);
    vector2 operator+(componentT b);
    void operator+=(componentT b);
    vector2 sub(componentT b);
    void sub_eq(componentT b);
    static vector2 sub(vector2& a,componentT b);
    vector2 operator-(componentT b);
    void operator-=(componentT b);
    vector2 mul(componentT b);
    void mul_eq(componentT b);
    static vector2 mul(vector2& a,componentT b);
    vector2 operator*(componentT b);
    void operator*=(componentT b);
    vector2 div(componentT b);
    void div_eq(componentT b);
    static vector2 div(vector2& a,componentT b);
    vector2 operator/(componentT b);
    void operator/=(componentT b);
    componentT length(componentT b);
    void length_c_eq(componentT b);
    void length_l_eq(componentT b);
    void operator=(componentT& a);
    bool equals(componentT b);
    static bool equals(vector2& a,componentT b);
    bool any_equals(componentT b);
    static bool any_equals(vector2& a,componentT b);

    bool isLargerThan_l(vector2& b);
    bool operator>(vector2& b);
    static bool isLargerThan_l(vector2& a,vector2& b);
    bool isLargerThanOrEqual_l(vector2& b);
    bool operator>=(vector2& b);
    static bool isLargerThanOrEqual_l(vector2& a,vector2& b);
    bool isSmallerThan_l(vector2& b);
    bool operator<(vector2& b);
    static bool isSmallerThan_l(vector2& a,vector2& b);
    bool isSmallerThanOrEqual_l(vector2& b);
    bool operator<=(vector2& b);
    static bool isSmallerThanOrEqual_l(vector2& a,vector2& b);

    
};
