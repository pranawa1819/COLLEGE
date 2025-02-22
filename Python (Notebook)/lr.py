import numpy as np
import pandas as pd


class CustomLinearRegression:
    def __init__(self, alpha=0.0001, epoch=10):
        # Randomly initializing weights and bias
        self.w1 = np.random.random()
        self.w2 = np.random.random()
        self.b = np.random.random()
        self.alpha = alpha
        self.epoch = epoch

    def fit(self, X, y):
        # Ensure necessary columns are present
        if not all(col in X.columns for col in ["X2 house age", "X3 distance to the nearest MRT station"]):
            raise ValueError("X must contain 'X2 house age' and 'X3 distance to the nearest MRT station' columns.")

        self.num_rec = X.shape[0]
        for _ in range(self.epoch):
            y_hat = self.predict(X)
            diff = y - y_hat

            grad_w1 = (2 / self.num_rec) * np.sum(diff * X["X2 house age"])
            grad_w2 = (2 / self.num_rec) * np.sum(diff * X["X3 distance to the nearest MRT station"])
            grad_b = (2 / self.num_rec) * np.sum(diff)

            self.w1 -= self.alpha * grad_w1
            self.w2 -= self.alpha * grad_w2
            self.b -= self.alpha * grad_b

    def predict(self, X):
        return (
            self.w1 * X["X2 house age"]
            + self.w2 * X["X3 distance to the nearest MRT station"]
            + self.b
        )

    def loss_mse(self, y, y_hat):
        return np.mean((y - y_hat) ** 2)


class CustomLinearRegression2:
    def __init__(self, alpha=0.0001, epoch=10):
        # Randomly initializing weights and bias
        self.alpha = alpha
        self.epoch = epoch
        self.w = None
        self.b = np.random.random()
    
    

    def fit(self, X: pd.DataFrame | pd.Series | np.ndarray, y: pd.Series | np.ndarray):
        self.num_rec, self.num_features = X.shape

        # Conversion logic
        if isinstance(X, pd.DataFrame | pd.Series) and isinstance(y, pd.Series):  # Check if X is a DataFrame or Series
            X = X.to_numpy()  # Convert to NumPy array if it is a DataFrame
            y = y.to_numpy()  # Convert to NumPy array if it is a Series
        elif isinstance(X, np.ndarray) and isinstance(y, np.ndarray):  # Check if X is a NumPy array
            pass
        else:
            raise ValueError("Either X or y is not a Pandas DataFrame, Series, or NumPy array")

        self.w = np.random.random(self.num_features)  # Initialize weights

        for _ in range(self.epoch):
            y_hat = self.predict(X)  # Predict values
            diff = y - y_hat

            grad_w = -(2 / self.num_rec) * np.dot(diff, X)
            grad_b = -(2 / self.num_rec) * np.sum(diff)

            self.w -= self.alpha * grad_w
            self.b -= self.alpha * grad_b

    def predict(self, X):
        return (np.dot(X, self.w) + self.b)

    def loss_mse(self, y, y_hat):
        return np.mean((y - y_hat) ** 2)