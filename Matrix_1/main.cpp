#include "Matrix.h"

matrix X_k0({ { 0 },
				{ 0 },
				{ 0 },
				{ 0 } });

matrix X_k1({ { 0 },
				{ 0 },
				{ 0 },
				{ 0 } });
matrix P_kp({ { 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 } });

matrix P_k0({ { 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 } });

bool flag = false;

matrix predictState(double X0, double Y0, double Vx0, double Vy0, double dT, double ax, double ay, const matrix& A, const matrix& B, const matrix& U)
{

	matrix X_kp({ { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } });

	return X_kp = A * X_k0 + B * U;

}

void initialCovariance(double dx, double dy, double dVx, double dVy)
{
	matrix P_first({ { pow(dx, 2), 0, 0, 0 },
					{ 0, pow(dy, 2), 0, 0 },
					{ 0, 0, pow(dVx, 2), 0 },
					{ 0, 0, 0, pow(dVy, 2) } });
	P_k0 = P_first;
}

matrix predictCovariance(double dT, matrix& A)
{


	if (!flag)
	{
		initialCovariance(50, 50, 5, 5);
	}
	else
	{

		flag = true;
	}

	return P_kp = A * P_k0 * Transponierte(A);;
}

matrix countKalmanGain(double dT, matrix& H, matrix& A, matrix& KG)
{
	matrix R({ { 1, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 } });

	matrix P_kp = predictCovariance(dT, A);

	return KG = P_kp * Transponierte(H) / (H * P_kp * Transponierte(H) + R);
}

matrix getObservation(const matrix& Ym)
{
	matrix Y({ { 0 },
				{ 0 },
				{ 0 },
				{ 0 } });
	matrix C({ { 1, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 } });
	matrix Z({ { 50 },
				{ 50 },
				{ 2 },
				{ 2 } });

	return Y = C * Ym + Z;

}


matrix countCurrentState(double X0, double Y0, double Vx0, double Vy0, double dT, double ax, double ay, const matrix& observation)
{
	matrix A({ { 1, 0, dT, 0 },
				{ 0, 1, 0, dT },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 } });
	matrix B({ { 0.5 * pow(dT,2), 0 },
	{ 0, 0.5 * pow(dT,2) },
	{ dT, 0 },
	{ 0, dT } });
	matrix U({ { ax },
	{ ay }, });
	matrix H({ { 1, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 } });
	matrix I({ { 1, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 } });
	matrix P_k1({ { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } });
	matrix X_kp({ { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } });
	matrix KG({ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } });

	KG = countKalmanGain(dT, A, H, KG);
	
	X_kp = predictState(X0, Y0, Vx0, Vy0, dT, ax, ay, A, B, U);
	/*X_k1 = X_kp + KG*(Y - H * X_kp)*/


	X_k1 = X_kp + KG * (getObservation(observation) - H * X_kp);
	P_k1 = (I - KG * H) * P_kp;


	X_k0 = X_k1;
	P_k0 = P_k1;

	return X_k1;
}


int main()
{
	matrix Result({ { 0 },
					{ 0 },
					{ 0 },
					{ 0 } });

	matrix Observation({ { 4260 },
							{ 3100 },
							{ 282 },
							{ 122 } });
	//						  (X0,   Y0,   Vx,  Vy, dT, ax, ay, Ym)
	Result = countCurrentState(4000, 3000, 280, 120, 1, 2, 1.5, Observation);
	Result.PrintMatrix();
	return 0;
}
