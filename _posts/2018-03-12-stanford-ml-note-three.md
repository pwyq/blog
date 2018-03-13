---
title: Study Note of Machine Learning (III)
date: 2018-03-12 20:28
categories: 
    - study
tags:
    - Machine Learning
    - Note
description: Study Note of Stanford Machine Learning (Chap. 4)
---

# Chap. 4 - Neural Networks: Representation
## Non-linear Hypotheses
Performing linear regression with a complex set of data with many features is very unwieldy. Say you wanted to create a hypothesis from three (3) features that included all the quadratic terms:

$$\begin{align*}& g(\theta_0 + \theta_1x_1^2 + \theta_2x_1x_2 + \theta_3x_1x_3 \newline& + \theta_4x_2^2 + \theta_5x_2x_3 \newline& + \theta_6x_3^2 )\end{align*}$$

That gives us 6 features. The exact way to calculate how many features for all polynomial terms is the combination function with repetition [link][2].  $$\frac{(n+r-1)!}{r!(n-1)!}$$. In this case we are taking all two-element combinations of three features: $$\frac{(3 + 2 - 1)!}{(2!\cdot (3-1)!)}$$ = $$\frac{4!}{4} = 6$$. (Note: you do not have to know these formulas, I just found it helpful for understanding).

For 100 features, if we wanted to make them quadratic we would get $$\frac{(100 + 2 - 1)!}{(2\cdot (100-1)!)} = 5050$$ resulting new features.

We can approximate the growth of the number of new features we get with all quadratic terms with $$\mathcal{O}(n^2/2)$$. And if you wanted to include all cubic terms in your hypothesis, the features would grow asymptotically at $$\mathcal{O}(n^3)$$. These are very steep growths, so as the number of our features increase, the number of quadratic or cubic features increase very rapidly and becomes quickly impractical.

Example: let our training set be a collection of 50 x 50 pixel black-and-white photographs, and our goal will be to classify which ones are photos of cars. Our feature set size is then n = 2500 if we compare every pair of pixels.

Now let's say we need to make a quadratic hypothesis function. With quadratic features, our growth is $$\mathcal{O}(n^2/2)$$. So our total features will be about $$2500^2 / 2 = 3125000$$, which is very impractical.

Neural networks offers an alternate way to perform machine learning when we have complex hypotheses with many features.

## Neurons and the Brain
Neural networks are limited imitations of how our own brains work. They've had a big recent resurgence because of advances in computer hardware.

There is evidence that the brain uses only one "learning algorithm" for all its different functions. Scientists have tried cutting (in an animal brain) the connection between the ears and the auditory cortex and rewiring the optical nerve with the auditory cortex to find that the auditory cortex literally learns to see.

This principle is called "neuroplasticity" and has many examples and experimental evidence.

## Model Representation I
Let's examine how we will represent a hypothesis function using neural networks.

At a very simple level, neurons are basically computational units that take input (dendrites) as electrical input (called "spikes") that are channeled to outputs (axons).

In our model, our dendrites are like the input features $$x_1\cdots x_n$$, and the output is the result of our hypothesis function:

In this model our x0 input node is sometimes called the "bias unit." It is always equal to 1.

In neural networks, we use the same logistic function as in classification: $$\frac{1}{1 + e^{-\theta^Tx}}$$. In neural networks however we sometimes call it a sigmoid (logistic) activation function.

Our "theta" parameters are sometimes instead called "weights" in the neural networks model.

Visually, a simplistic representation looks like:

$$\begin{bmatrix}x_0 \newline x_1 \newline x_2 \newline \end{bmatrix}\rightarrow\begin{bmatrix}\ \ \ \newline \end{bmatrix}\rightarrow h_\theta(x)$$

Our input nodes (layer 1) go into another node (layer 2), and are output as the hypothesis function.

The first layer is called the "input layer" and the final layer the "output layer," which gives the final value computed on the hypothesis.

We can have intermediate layers of nodes between the input and output layers called the "hidden layer."

We label these intermediate or "hidden" layer nodes $$a^2_0 \cdots a^2_n$$ and call them "activation units."

$$\begin{align*}& a_i^{(j)} = \text{"activation" of unit $i$ in layer $j$} \newline& \Theta^{(j)} = \text{matrix of weights controlling function mapping from layer $j$ to layer $j+1$}\end{align*}$$

If we had one hidden layer, it would look visually something like:

$$\begin{bmatrix}x_0 \newline x_1 \newline x_2 \newline x_3\end{bmatrix}\rightarrow\begin{bmatrix}a_1^{(2)} \newline a_2^{(2)} \newline a_3^{(2)} \newline \end{bmatrix}\rightarrow h_\theta(x)$$

The values for each of the "activation" nodes is obtained as follows:

$$\begin{align*} a_1^{(2)} = g(\Theta_{10}^{(1)}x_0 + \Theta_{11}^{(1)}x_1 + \Theta_{12}^{(1)}x_2 + \Theta_{13}^{(1)}x_3) \newline a_2^{(2)} = g(\Theta_{20}^{(1)}x_0 + \Theta_{21}^{(1)}x_1 + \Theta_{22}^{(1)}x_2 + \Theta_{23}^{(1)}x_3) \newline a_3^{(2)} = g(\Theta_{30}^{(1)}x_0 + \Theta_{31}^{(1)}x_1 + \Theta_{32}^{(1)}x_2 + \Theta_{33}^{(1)}x_3) \newline h_\Theta(x) = a_1^{(3)} = g(\Theta_{10}^{(2)}a_0^{(2)} + \Theta_{11}^{(2)}a_1^{(2)} + \Theta_{12}^{(2)}a_2^{(2)} + \Theta_{13}^{(2)}a_3^{(2)}) \newline \end{align*}$$

This is saying that we compute our activation nodes by using a 3×4 matrix of parameters. We apply each row of the parameters to our inputs to obtain the value for one activation node. Our hypothesis output is the logistic function applied to the sum of the values of our activation nodes, which have been multiplied by yet another parameter matrix $$\Theta^{(2)}$$ containing the weights for our second layer of nodes.

Each layer gets its own matrix of weights, $$\Theta^{(j)}$$.

The dimensions of these matrices of weights is determined as follows:

$$\text{If network has $s_j$ units in layer $j$ and $s_{j+1}$ units in layer $j+1$, then $\Theta^{(j)}$ will be of dimension $s_{j+1} \times (s_j + 1)$.}$$

The +1 comes from the addition in $$\Theta^{(j)}$$ of the "bias nodes," $$x_0$$ and $$\Theta_0^{(j)}$$. In other words the output nodes will not include the bias nodes while the inputs will.

Example: layer 1 has 2 input nodes and layer 2 has 4 activation nodes. Dimension of $$\Theta^{(1)}$$ is going to be 4×3 where $$s_j = 2$$ and $$s_{j+1} = 4$$, so $$s_{j+1} \times (s_j + 1) = 4 \times 3$$.

## Model Representation II
In this section we'll do a vectorized implementation of the above functions. We're going to define a new variable $$z_k^{(j)}$$ that encompasses the parameters inside our g function. In our previous example if we replaced the variable z for all the parameters we would get:

$$\begin{align*}a_1^{(2)} = g(z_1^{(2)}) \newline a_2^{(2)} = g(z_2^{(2)}) \newline a_3^{(2)} = g(z_3^{(2)}) \newline \end{align*}$$

In other words, for layer j=2 and node k, the variable z will be:

$$z_k^{(2)} = \Theta_{k,0}^{(1)}x_0 + \Theta_{k,1}^{(1)}x_1 + \cdots + \Theta_{k,n}^{(1)}x_n$$

The vector representation of x and $$z^{j}$$ is:

$$\begin{align*}x = \begin{bmatrix}x_0 \newline x_1 \newline\cdots \newline x_n\end{bmatrix} &z^{(j)} = \begin{bmatrix}z_1^{(j)} \newline z_2^{(j)} \newline\cdots \newline z_n^{(j)}\end{bmatrix}\end{align*}$$

Setting $$x = a^{(1)}$$, we can rewrite the equation as:

$$z^{(j)} = \Theta^{(j-1)}a^{(j-1)}$$

We are multiplying our matrix $$\Theta^{(j-1)}$$ with dimensions $$s_j\times (n+1)$$ (where $$s_j$$ is the number of our activation nodes) by our vector $$a^{(j-1)}$$ with height (n+1). This gives us our vector $$z^{(j)}$$ with height $$s_j$$.

Now we can get a vector of our activation nodes for layer j as follows:

$$a^{(j)} = g(z^{(j)})$$

Where our function g can be applied element-wise to our vector $$z^{(j)}$$.

We can then add a bias unit (equal to 1) to layer j after we have computed $$a^{(j)}$$. This will be element $$a_0^{(j)}$$ and will be equal to 1.

To compute our final hypothesis, let's first compute another z vector:

$$z^{(j+1)} = \Theta^{(j)}a^{(j)}$$

We get this final z vector by multiplying the next theta matrix after $$\Theta^{(j-1)}$$ with the values of all the activation nodes we just got.

This last theta matrix $$\Theta^{(j)}$$ will have only one row so that our result is a single number.

We then get our final result with:

$$h_\Theta(x) = a^{(j+1)} = g(z^{(j+1)})$$

Notice that in this last step, between layer j and layer j+1, we are doing exactly the same thing as we did in logistic regression.

Adding all these intermediate layers in neural networks allows us to more elegantly produce interesting and more complex non-linear hypotheses.

## Examples and Intuitions I
A simple example of applying neural networks is by predicting $$x_1$$ AND $$x_2$$, which is the logical 'and' operator and is only true if both $$x_1$$ and $$x_2$$ are 1.

The graph of our functions will look like:

$$\begin{align*}\begin{bmatrix}x_0 \newline x_1 \newline x_2\end{bmatrix} \rightarrow\begin{bmatrix}g(z^{(2)})\end{bmatrix} \rightarrow h_\Theta(x)\end{align*}$$

Remember that $$x_0$$ is our bias variable and is always 1.

Let's set our first theta matrix as:

$$\Theta^{(1)} =\begin{bmatrix}-30 & 20 & 20\end{bmatrix}$$

This will cause the output of our hypothesis to only be positive if both $$x_1$$ and $$x_2$$ are 1. In other words:

$$\begin{align*}& h_\Theta(x) = g(-30 + 20x_1 + 20x_2) \newline \newline & x_1 = 0 \ \ and \ \ x_2 = 0 \ \ then \ \ g(-30) \approx 0 \newline & x_1 = 0 \ \ and \ \ x_2 = 1 \ \ then \ \ g(-10) \approx 0 \newline & x_1 = 1 \ \ and \ \ x_2 = 0 \ \ then \ \ g(-10) \approx 0 \newline & x_1 = 1 \ \ and \ \ x_2 = 1 \ \ then \ \ g(10) \approx 1\end{align*}$$

So we have constructed one of the fundamental operations in computers by using a small neural network rather than using an actual AND gate. Neural networks can also be used to simulate all the other logical gates.

## Examples and Intuitions II
The $$\theta^(1)$$ matrices for AND, NOR, and OR are:

$$\begin{align*}AND:\newline\Theta^{(1)} &=\begin{bmatrix}-30 & 20 & 20\end{bmatrix} \newline NOR:\newline\Theta^{(1)} &= \begin{bmatrix}10 & -20 & -20\end{bmatrix} \newline OR:\newline\Theta^{(1)} &= \begin{bmatrix}-10 & 20 & 20\end{bmatrix} \newline\end{align*}$$

We can combine these to get the XNOR logical operator (which gives 1 if $$x_1$$ and $$x_2$$ are both 0 or both 1).

$$\begin{align*}\begin{bmatrix}x_0 \newline x_1 \newline x_2\end{bmatrix} \rightarrow\begin{bmatrix}a_1^{(2)} \newline a_2^{(2)} \end{bmatrix} \rightarrow\begin{bmatrix}a^{(3)}\end{bmatrix} \rightarrow h_\Theta(x)\end{align*}$$

For the transition between the first and second layer, we'll use a $$\theta^(1)$$ matrix that combines the values for AND and NOR:

$$\Theta^{(1)} =\begin{bmatrix}-30 & 20 & 20 \newline 10 & -20 & -20\end{bmatrix}$$

For the transition between the second and third layer, we'll use a $$\theta^(2)$$ matrix that uses the value for OR:

$$\Theta^{(2)} =\begin{bmatrix}-10 & 20 & 20\end{bmatrix}$$

Let's write out the values for all our nodes:

$$\begin{align*}& a^{(2)} = g(\Theta^{(1)} \cdot x) \newline& a^{(3)} = g(\Theta^{(2)} \cdot a^{(2)}) \newline& h_\Theta(x) = a^{(3)}\end{align*}$$

And there we have the XNOR operator using two hidden layers!

## Multiclass Classification
To classify data into multiple classes, we let our hypothesis function return a vector of values. Say we wanted to classify our data into one of four final resulting classes:

$$\begin{align*}\begin{bmatrix}x_0 \newline x_1 \newline x_2 \newline\cdots \newline x_n\end{bmatrix} \rightarrow\begin{bmatrix}a_0^{(2)} \newline a_1^{(2)} \newline a_2^{(2)} \newline\cdots\end{bmatrix} \rightarrow\begin{bmatrix}a_0^{(3)} \newline a_1^{(3)} \newline a_2^{(3)} \newline\cdots\end{bmatrix} \rightarrow \cdots \rightarrow\begin{bmatrix}h_\Theta(x)_1 \newline h_\Theta(x)_2 \newline h_\Theta(x)_3 \newline h_\Theta(x)_4 \newline\end{bmatrix} \rightarrow\end{align*}$$

Our final layer of nodes, when multiplied by its theta matrix, will result in another vector, on which we will apply the g() logistic function to get a vector of hypothesis values.

Our resulting hypothesis for one set of inputs may look like:

$$h_\Theta(x) =\begin{bmatrix}0 \newline 0 \newline 1 \newline 0 \newline\end{bmatrix}$$

In which case our resulting class is the third one down, or $$h_\Theta(x)_3$$.

We can define our set of resulting classes as y:


Our final value of our hypothesis for a set of inputs will be one of the elements in y.


# Chap. 5 - ML:Neural Networks: Learning
## Cost Function
Let's first define a few variables that we will need to use:

a) L= total number of layers in the network

b) $$s_l$$ = number of units (not counting bias unit) in layer l

c) K= number of output units/classes

Recall that in neural networks, we may have many output nodes. We denote $$h_\Theta(x)_k$$ as being a hypothesis that results in the $$k^{th}$$ output.

Our cost function for neural networks is going to be a generalization of the one we used for logistic regression.

Recall that the cost function for regularized logistic regression was:

$$J(\theta) = - \frac{1}{m} \sum_{i=1}^m \large[ y^{(i)}\ \log (h_\theta (x^{(i)})) + (1 - y^{(i)})\ \log (1 - h_\theta(x^{(i)}))\large] + \frac{\lambda}{2m}\sum_{j=1}^n \theta_j^2$$

For neural networks, it is going to be slightly more complicated:

$$\begin{gather*}\large J(\Theta) = - \frac{1}{m} \sum_{i=1}^m \sum_{k=1}^K \left[y^{(i)}_k \log ((h_\Theta (x^{(i)}))_k) + (1 - y^{(i)}_k)\log (1 - (h_\Theta(x^{(i)}))_k)\right] + \frac{\lambda}{2m}\sum_{l=1}^{L-1} \sum_{i=1}^{s_l} \sum_{j=1}^{s_{l+1}} ( \Theta_{j,i}^{(l)})^2\end{gather*}$$

We have added a few nested summations to account for our multiple output nodes. In the first part of the equation, between the square brackets, we have an additional nested summation that loops through the number of output nodes.

In the regularization part, after the square brackets, we must account for multiple theta matrices. The number of columns in our current theta matrix is equal to the number of nodes in our current layer (including the bias unit). The number of rows in our current theta matrix is equal to the number of nodes in the next layer (excluding the bias unit). As before with logistic regression, we square every term.

Note:

- the double sum simply adds up the logistic regression costs calculated for each cell in the output layer; and
- the triple sum simply adds up the squares of all the individual Θs in the entire network.
- the i in the triple sum does not refer to training example i

## Backpropagation Algorithm

"Backpropagation" is neural-network terminology for minimizing our cost function, just like what we were doing with gradient descent in logistic and linear regression.

Our goal is to compute:

$$\min_\Theta J(\Theta)$$

That is, we want to minimize our cost function J using an optimal set of parameters in theta.

In this section we'll look at the equations we use to compute the partial derivative of J(Θ):

$$\dfrac{\partial}{\partial \Theta_{i,j}^{(l)}}J(\Theta)$$

In back propagation we're going to compute for every node:

$$\delta_j^{(l)}$$ = "error" of node j in layer l

Recall that $$a_j^{(l)}$$ is activation node j in layer l.

For the last layer, we can compute the vector of delta values with:

$$\delta^{(L)} = a^{(L)} - y$$

Where L is our total number of layers and $$a^{(L)}$$ is the vector of outputs of the activation units for the last layer. So our "error values" for the last layer are simply the differences of our actual results in the last layer and the correct outputs in y.

To get the delta values of the layers before the last layer, we can use an equation that steps us back from right to left:

$$\delta^{(l)} = ((\Theta^{(l)})^T \delta^{(l+1)})\ .*\ g'(z^{(l)})$$

The delta values of layer l are calculated by multiplying the delta values in the next layer with the theta matrix of layer l. We then element-wise multiply that with a function called g', or g-prime, which is the derivative of the activation function g evaluated with the input values given by z(l).

The g-prime derivative terms can also be written out as:

$$g'(u) = g(u)\ .*\ (1 - g(u))$$

The full back propagation equation for the inner nodes is then:

$$\delta^{(l)} = ((\Theta^{(l)})^T \delta^{(l+1)})\ .*\ a^{(l)}\ .*\ (1 - a^{(l)})$$

A. Ng states that the derivation and proofs are complicated and involved, but you can still implement the above equations to do back propagation without knowing the details.

We can compute our partial derivative terms by multiplying our activation values and our error values for each training example t:

$$\dfrac{\partial J(\Theta)}{\partial \Theta_{i,j}^{(l)}} = \frac{1}{m}\sum_{t=1}^m a_j^{(t)(l)} {\delta}_i^{(t)(l+1)}$$

This however ignores regularization, which we'll deal with later.

Note: $$\delta^{l+1}$$ and $$a^{l+1}$$ are vectors with $$s_{l+1}$$ elements. Similarly, $$\ a^{(l)}$$ is a vector with $$s_l$$ elements. Multiplying them produces a matrix that is $$s_{l+1}$$ by $$s_l$$ which is the same dimension as $$\Theta^{(l)}$$.
That is, the process produces a gradient term for every element in $$\Theta^{(l)}$$. (Actually, $$\Theta^{(l)}$$ has $$s_{l}$$ + 1 column, so the dimensionality is not exactly the same).

We can now take all these equations and put them together into a backpropagation algorithm:

### Back propagation Algorithm

Given training set $$\lbrace (x^{(1)}, y^{(1)}) \cdots (x^{(m)}, y^{(m)})\rbrace$$

Set $$\Delta^{(l)}_{i,j}$$ := 0 for all (l,i,j)

For training example t =1 to m:

- Set $$a^{(1)} := x^{(t)}$$
- Perform forward propagation to compute $$a^{(l)}$$ for l=2,3,…,L
- Using $$y^{(t)}$$, compute $$\delta^{(L)} = a^{(L)} - y^{(t)}$$
- Compute $$\delta^{(L-1)}, \delta^{(L-2)},\dots,\delta^{(2)}$$ using $$\delta^{(l)} = ((\Theta^{(l)})^T \delta^{(l+1)})\ .*\ a^{(l)}\ .*\ (1 - a^{(l)})$$
- $$\Delta^{(l)}_{i,j} := \Delta^{(l)}_{i,j} + a_j^{(l)} \delta_i^{(l+1)}$$ or with vectorization, $$\Delta^{(l)} := \Delta^{(l)} + \delta^{(l+1)}(a^{(l)})^T$$
- $$D^{(l)}_{i,j} := \dfrac{1}{m}\left(\Delta^{(l)}_{i,j} + \lambda\Theta^{(l)}_{i,j}\right)$$ If j≠0 NOTE: Typo in lecture slide omits outside parentheses. This version is correct.
- $$D^{(l)}_{i,j} := \dfrac{1}{m}\Delta^{(l)}_{i,j}$$ If j=0

The capital-delta matrix is used as an "accumulator" to add up our values as we go along and eventually compute our partial derivative.

The actual proof is quite involved, but, the $$D^{(l)}_{i,j}$$ terms are the partial derivatives and the results we are looking for:

$$D_{i,j}^{(l)} = \dfrac{\partial J(\Theta)}{\partial \Theta_{i,j}^{(l)}}.$$

## Backpropagation Intuition
The cost function is:

$$\begin{gather*}J(\theta) = - \frac{1}{m} \sum_{t=1}^m\sum_{k=1}^K \left[ y^{(t)}_k \ \log (h_\theta (x^{(t)}))_k + (1 - y^{(t)}_k)\ \log (1 - h_\theta(x^{(t)})_k)\right] + \frac{\lambda}{2m}\sum_{l=1}^{L-1} \sum_{i=1}^{s_l} \sum_{j=1}^{s_l+1} ( \theta_{j,i}^{(l)})^2\end{gather*}$$

If we consider simple non-multiclass classification (k = 1) and disregard regularization, the cost is computed with:

$$cost(t) =y^{(t)} \ \log (h_\theta (x^{(t)})) + (1 - y^{(t)})\ \log (1 - h_\theta(x^{(t)}))$$

More intuitively you can think of that equation roughly as:

$$cost(t) \approx (h_\theta(x^{(t)})-y^{(t)})^2$$

Intuitively, $$\delta_j^{(l)}$$ is the "error" for $$a^{(l)}_j$$ (unit j in layer l)

More formally, the delta values are actually the derivative of the cost function:

$$\delta_j^{(l)} = \dfrac{\partial}{\partial z_j^{(l)}} cost(t)$$

Recall that our derivative is the slope of a line tangent to the cost function, so the steeper the slope the more incorrect we are.

Note: In lecture, sometimes i is used to index a training example. Sometimes it is used to index a unit in a layer. In the Back Propagation Algorithm described here, t is used to index a training example rather than overloading the use of i.

## Implementation Note: Unrolling Parameters
With neural networks, we are working with sets of matrices:

$$\begin{align*} \Theta^{(1)}, \Theta^{(2)}, \Theta^{(3)}, \dots \newline D^{(1)}, D^{(2)}, D^{(3)}, \dots \end{align*}$$

In order to use optimizing functions such as "fminunc()", we will want to "unroll" all the elements and put them into one long vector:

If the dimensions of Theta1 is 10x11, Theta2 is 10x11 and Theta3 is 1x11, then we can get back our original matrices from the "unrolled" versions as follows:

NOTE: The lecture slides show an example neural network with 3 layers. However, 3 theta matrices are defined: Theta1, Theta2, Theta3. There should be only 2 theta matrices: Theta1 (10 x 11), Theta2 (1 x 11).

## Gradient Checking
Gradient checking will assure that our backpropagation works as intended.

We can approximate the derivative of our cost function with:

$$\dfrac{\partial}{\partial\Theta}J(\Theta) \approx \dfrac{J(\Theta + \epsilon) - J(\Theta - \epsilon)}{2\epsilon}$$

With multiple theta matrices, we can approximate the derivative with respect to $$Θ_j$$ as follows:

$$\dfrac{\partial}{\partial\Theta_j}J(\Theta) \approx \dfrac{J(\Theta_1, \dots, \Theta_j + \epsilon, \dots, \Theta_n) - J(\Theta_1, \dots, \Theta_j - \epsilon, \dots, \Theta_n)}{2\epsilon}$$

A good small value for $${\epsilon}$$ (epsilon), guarantees the math above to become true. If the value be much smaller, may we will end up with numerical problems. The professor Andrew usually uses the value $${\epsilon = 10^{-4}}$$.

We are only adding or subtracting epsilon to the $$Theta_j$$ matrix. In octave we can do it as follows:

We then want to check that gradApprox ≈ deltaVector.

Once you've verified once that your backpropagation algorithm is correct, then you don't need to compute gradApprox again. The code to compute gradApprox is very slow.

## Random Initialization
Initializing all theta weights to zero does not work with neural networks. When we backpropagate, all nodes will update to the same value repeatedly.

Instead we can randomly initialize our weights:

Initialize each $$\Theta^{(l)}_{ij}$$ to a random value between$$ [-\epsilon,\epsilon]$$:

$$\epsilon = \dfrac{\sqrt{6}}{\sqrt{\mathrm{Loutput} + \mathrm{Linput}}}$$

$$\Theta^{(l)} = 2 \epsilon \; \mathrm{rand}(\mathrm{Loutput}, \mathrm{Linput} + 1) - \epsilon$$

rand(x,y) will initialize a matrix of random real numbers between 0 and 1. (Note: this epsilon is unrelated to the epsilon from Gradient Checking)

Why use this method? This paper may be useful: https://web.stanford.edu/class/ee373b/nninitialization.pdf

## Putting it Together
First, pick a network architecture; choose the layout of your neural network, including how many hidden units in each layer and how many layers total.

Number of input units = dimension of features $$x^{(i)}$$
Number of output units = number of classes
Number of hidden units per layer = usually more the better (must balance with cost of computation as it increases with more hidden units)
Defaults: 1 hidden layer. If more than 1 hidden layer, then the same number of units in every hidden layer.
Training a Neural Network

Randomly initialize the weights
Implement forward propagation to get $$h_\theta(x^{(i)})$$
Implement the cost function
Implement backpropagation to compute partial derivatives
Use gradient checking to confirm that your backpropagation works. Then disable gradient checking.
Use gradient descent or a built-in optimization function to minimize the cost function with the weights in theta.
When we perform forward and back propagation, we loop on every training example:


## Explanation of Derivatives Used in Backpropagation
We know that for a logistic regression classifier (which is what all of the output neurons in a neural network are), we use the cost function, $$J(\theta) = -ylog(h_{\theta}(x)) - (1-y)log(1-h_{\theta}(x))$$, and apply this over the K output neurons, and for all m examples.
he equation to compute the partial derivatives of the theta terms in the output neurons:

$$\frac{\partial J(\theta)}{\partial \theta^{(L-1)}} = \frac{\partial J(\theta)}{\partial a^{(L)}} \frac{\partial a^{(L)}}{\partial z^{(L)}} \frac{\partial z^{(L)}}{\partial \theta^{(L-1)}}$$

And the equation to compute partial derivatives of the theta terms in the [last] hidden layer neurons (layer L-1):

$$\frac{\partial J(\theta)}{\partial \theta^{(L-2)}} = \frac{\partial J(\theta)}{\partial a^{(L)}} \frac{\partial a^{(L)}}{\partial z^{(L)}} \frac{\partial z^{(L)}}{\partial a^{(L-1)}} \frac{\partial a^{(L-1)}}{\partial z^{(L-1)}} \frac{\partial z^{(L-1)}}{\partial \theta^{(L-2)}}$$

Clearly they share some pieces in common, so a delta term ($$δ^{(L)}$$) can be used for the common pieces between the output layer and the hidden layer immediately before it (with the possibility that there could be many hidden layers if we wanted):

$$\delta^{(L)} = \frac{\partial J(\theta)}{\partial a^{(L)}} \frac{\partial a^{(L)}}{\partial z^{(L)}}$$

And we can go ahead and use another delta term ($$δ^{(L−1)}$$) for the pieces that would be shared by the final hidden layer and a hidden layer before that, if we had one. Regardless, this delta term will still serve to make the math and implementation more concise.

$$\delta^{(L-1)} = \frac{\partial J(\theta)}{\partial a^{(L)}} \frac{\partial a^{(L)}}{\partial z^{(L)}} \frac{\partial z^{(L)}}{\partial a^{(L-1)}} \frac{\partial a^{(L-1)}}{\partial z^{(L-1)}}$$

$$\delta^{(L-1)} = \delta^{(L)} \frac{\partial z^{(L)}}{\partial a^{(L-1)}} \frac{\partial a^{(L-1)}}{\partial z^{(L-1)}}$$

With these delta terms, our equations become:

$$\frac{\partial J(\theta)}{\partial \theta^{(L-1)}} = \delta^{(L)} \frac{\partial z^{(L)}}{\partial \theta^{(L-1)}}$$

$$\frac{\partial J(\theta)}{\partial \theta^{(L-2)}} = \delta^{(L-1)} \frac{\partial z^{(L-1)}}{\partial \theta^{(L-2)}}$$

Now, time to evaluate these derivatives. Let's start with the output layer:

$$\frac{\partial J(\theta)}{\partial \theta^{(L-1)}} = \delta^{(L)} \frac{\partial z^{(L)}}{\partial \theta^{(L-1)}}$$

Using $$\delta^{(L)} = \frac{\partial J(\theta)}{\partial a^{(L)}} \frac{\partial a^{(L)}}{\partial z^{(L)}}$$, we need to evaluate both partial derivatives.

Given $$J(\theta) = -ylog(a^{(L)}) - (1-y)log(1-a^{(L)})$$, where $$a^{(L)} = h_{\theta}(x))$$, the partial derivative is:

$$\frac{\partial J(\theta)}{\partial a^{(L)}} = \frac{1-y}{1-a^{(L)}} - \frac{y}{a^{(L)}}$$

And given a=g(z), where $$g = \frac{1}{1+e^{-z}}$$, the partial derivative is:

$$\frac{\partial a^{(L)}}{\partial z^{(L)}} = a^{(L)}(1-a^{(L)})$$

So, let's substitute these in for $$δ^{(L)}$$:

$$\delta^{(L)} = \frac{\partial J(\theta)}{\partial a^{(L)}} \frac{\partial a^{(L)}}{\partial z^{(L)}}$$

$$\delta^{(L)} = (\frac{1-y}{1-a^{(L)}} - \frac{y}{a^{(L)}}) (a^{(L)}(1-a^{(L)}))$$

$$\delta^{(L)} =a^{(L)} - y$$

So, for a 3-layer network (L=3),

$$\delta^{(3)} =a^{(3)} - y$$

Note that this is the correct equation, as given in our notes. Now, given z=θ∗input, and in layer L the input is $$a^{(L−1)}$$, the partial derivative is:

$$\frac{\partial z^{(L)}}{\partial \theta^{(L-1)}} = a^{(L-1)}$$

Put it together for the output layer:

$$\frac{\partial J(\theta)}{\partial \theta^{(L-1)}} = \delta^{(L)} \frac{\partial z^{(L)}}{\partial \theta^{(L-1)}}$$

$$\frac{\partial J(\theta)}{\partial \theta^{(L-1)}} = (a^{(L)} - y) (a^{(L-1)})$$

Let's continue on for the hidden layer (let's assume we only have 1 hidden layer):

$$\frac{\partial J(\theta)}{\partial \theta^{(L-2)}} = \delta^{(L-1)} \frac{\partial z^{(L-1)}}{\partial \theta^{(L-2)}}$$

Let's figure out $$δ{(L−1)}$$. Once again, given z=θ∗input, the partial derivative is:

$$\frac{\partial z^{(L)}}{\partial a^{(L-1)}} = \theta^{(L-1)}$$

And: $$\frac{\partial a^{(L-1)}}{\partial z^{(L-1)}} = a^{(L-1)}(1-a^{(L-1)})$$

So, let's substitute these in for $$δ^{(L−1)}$$:

$$\delta^{(L-1)} = \delta^{(L)} \frac{\partial z^{(L)}}{\partial a^{(L-1)}} \frac{\partial a^{(L-1)}}{\partial z^{(L-1)}}$$

$$\delta^{(L-1)} = \delta^{(L)} (\theta^{(L-1)}) (a^{(L-1)}(1-a^{(L-1)}))$$

$$\delta^{(L-1)} = \delta^{(L)} \theta^{(L-1)} a^{(L-1)}(1-a^{(L-1)})$$

So, for a 3-layer network,

$$\delta^{(2)} = \delta^{(3)} \theta^{(2)} a^{(2)}(1-a^{(2)})$$

Put it together for the [last] hidden layer:

$$\frac{\partial J(\theta)}{\partial \theta^{(L-2)}} = \delta^{(L-1)} \frac{\partial z^{(L-1)}}{\partial \theta^{(L-2)}}$$

$$\frac{\partial J(\theta)}{\partial \theta^{(L-2)}} = (\delta^{(L)} \frac{\partial z^{(L)}}{\partial a^{(L-1)}} \frac{\partial a^{(L-1)}}{\partial z^{(L-1)}}) (a^{(L-2)})$$

$$\frac{\partial J(\theta)}{\partial \theta^{(L-2)}} = ((a^{(L)} - y) (\theta^{(L-1)})(a^{(L-1)}(1-a^{(L-1)}))) (a^{(L-2)})$$

## Deriving the Sigmoid Gradient Function
We let the sigmoid function be $$ \sigma(x) = \frac{1}{1 + e^{-x}}$$

Deriving the equation above yields to $$ (\frac{1}{1 + e^{-x}})^2 \frac {d}{ds} \frac{1}{1 + e^{-x}}$$

Which is equal to $$ (\frac{1}{1 + e^{-x}})^2 e^{-x} (-1)$$

$$ (\frac{1}{1 + e^{-x}}) (\frac{1}{1 + e^{-x}}) (-e^{-x})$$

$$ (\frac{1}{1 + e^{-x}}) (\frac{-e^{-x}}{1 + e^{-x}})$$

$$ \sigma(x)(1- \sigma(x))$$

### Additional Resources for Backpropagation

- Very thorough conceptual [example][3]
- [Short derivation of the backpropagation algorithm][4] 
- [Stanford University Deep Learning notes][5] 
- [Very thorough explanation and proof][6] 


# Reference
- [Stanford Machine Learning by Andrew Ng][1]

[1]: https://www.coursera.org/learn/machine-learning
[2]: http://www.mathsisfun.com/combinatorics/combinations-permutations.html
[3]: https://web.archive.org/web/20150317210621/https://www4.rgu.ac.uk/files/chapter3%20-%20bp.pdf
[4]: http://pandamatak.com/people/anand/771/html/node37.html
[5]: http://ufldl.stanford.edu/wiki/index.php/Backpropagation_Algorithm
[6]: http://neuralnetworksanddeeplearning.com/chap2.html
