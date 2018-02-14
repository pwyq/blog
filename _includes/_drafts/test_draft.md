# ML-Pedia

I was thrown, recklessly (and luckily), into the center of an AI project all of a sudden.
In recent days, my stupid and tiny brain was being continuously bombed by an unstoppable series of high-end abbreviation, 
like DQfD, CNN, RNN, D-DQN, HRL, DQL, IRL...(Stop!)
Oh dear, I could barely distinguish supervised learning and unsupervised learning at the time!

Hence, an encyclopedia-liked post will (hopefully) help me to better embrace all those `Learning`s and `Neural Network`s.

*If you find any mistake in this post, please comment or email me without hesitation! Sincerely, thank you!*


Some terms to consider when recording each term
- Links / Sources / Papers
- When the concept first occurred
- By who (individual/organization)
- Basic idea(s)
- Algorithm(s)
- Example(s)
- Application(s)

# Contents

- [Machine Learning](#machine-learning)
- [Rule-based Machine Learning](#rule-based-machine-learning)
    - [Rules](#rules)
- [Supervised Learning](#supervised-learning)
    - [Semi-supervised Learning](#semi-supervised-learning)
- [Unsupervised Learning](#unsupervised-learning)
- [Deep Learning](#deep-learning)
- [Deep Neural Networks](#deep-neural-networks)
- [Reinforcement Learning](#reinforcement-learning)
- [Temporal Difference Learning](#temporal-difference-learning)
- [Q-learning](#q-learning)
- [Deep Reinforcement Learning](#deep-reinforcement-learning)
- [Hierachical Reinforcement Learning](#hierachical-reinforcement-learning)
- [Deep Q-Learning](#deep-q-learning)
- [Deep Q-learning from Demonstrations](#deep-q-learning-from-demonstrations)
- [Feature Learning](#feature-learning)
- [Online Machine Learning](#online-machine-learning)
- [One-shot Learning](#one-shot-learning)
- [Meta Learning](#meta-learning)
- [Inverse Reinforcement Learning](#inverse-reinforcement-learning)
- [Bayesian Inverse Reinforcement Learning](#bayesian-inverse-reinforcement-learning)
- [Maximum Entropy Inverse Reinforcement Learning](#maximum-entropy-inverse-reinforcement-learning)
- [Convolutional Neural Network](#convolutional-neural-network)
- [Recurrent Neural Network](#recurrent-neural-network)
- [Deep Q-Network](#deep-q-network)
- [Double DQN](#double-dqn)
- [State-Action-Reward-State-Action](#state-action-reward-state-action)


## Machine Learning
    - Can be categorized as Supervised Learning, Unsupervised Learning and Reinforcement Learning.
    - Machine learning is about learning from data and making predictions and/or decisions [1].

## Rule-based Machine Learning
    - [Wiki][10]
    - A term in computer science intended to encompass any ML method that identifies, learns, or evolves 'rules' to store, manipulate or apply.
### Rules
Rules typically take the form of an `{IF:ELSE}` expression. Rule-based ML methods typically identify a set of rules that collectively comprise the prediciton model (or the knowledge base).

## Supervised Learning
    - [Wiki][7]
    - Supervised Learning deals with labeled data.

## Semi-supervised Learning
    - [Wiki][6]

## Unsupervised Learning
    - [Wiki][5]
    - Unsupervised Learning deals with no labeled data.

## Deep Learning
    - is a particular ML scheme.

## Deep Neural Networks

## Reinforcement Learning
    - RL
    - [Wiki][8]
    "RL is about an agent interacting with the environment, learning an optimal policy, by trail and error, for sequential desicion making problems in a wide range of fields in both natural and social sciences, and engineering" (Li, 2017).

## Temporal Difference Learning
    - TD Learning
    - [Wiki][11]: a prediciton-based ML method; it has been primarily been used for RL problem. It is central for RL [1].
    - SARSA and Q-learning are regarded as temporal difference learning [1].

## Q-learning
    - [Wiki][9]

## Deep Reinforcement Learning 
    - DRL
    - [Deep Reinforcement Learning: An Overview][1]
    - use deep neural networks (DL) to approximate components of RL (such as value function, state transition function and reward function) [1].

## Hierachical Reinforcement Learning
    - HRL
    - see the `HRL-intro.pptx`

## Deep Q-Learning

## Deep Q-learning from Demonstrations 
    - [DQfD][2]

## Feature Learning 
    - Representation Learning
    - [Wiki][3]
    - Supervised feature learning
    - Unsupervised feature learning

## Online Machine Learning
    - [Wiki][4]

## One-shot Learning
    - [Wiki][14]
    - One-shot learning is an object categorization problem in computer vision. Whereas most machine learning based object categorization algorithms require training on hundreds or thousands of images and very large datasets, one-shot learning aims to learn information about object categories from one, or only a few, training images.

## Meta Learning
    - Learning to learn
    - [wiki][15]
    - Meta learning is a subfield of machine learning where automatic learning algorithms are applied on metadata about machine learning experiments.

## Inverse Reinforcement Learning
    - Inverse Optimal Control, Inverse Optimal Planning
    - [Algorithms for IRL][17] by Andrew Ng

## Bayesian Inverse Reinforcement Learning 
    - [Bayesian IRL][16]

## Maximum Entropy Inverse Reinforcement Learning 
    - [Maximum Entropy IRL][18]
    - [Principle of maximum entropy][19]

## Convolutional Neural Network
    - CNN
    - A deep learning model
    - A feedforward deep neural network, with convolutional layers, pooling layers and fully connected layers [1].

## Recurrent Neural Network
    - RNN
    - is often used to process sequential inputs like speech and language, element by element, with hidden units to store history of past elements [1].

## Deep Q-Network
    - DQN

## Double DQN
    - D-DQN

## State-Action-Reward-State-Action
    - SARSA
    - [Wiki][12]
    - an algorithm for learning a [Markov Decision Process] policy, used in RL

[comment]: <Links>

[1]: https://arxiv.org/pdf/1701.07274.pdf
[2]: https://arxiv.org/abs/1704.03732
[3]: https://en.wikipedia.org/wiki/Feature_learning
[4]: https://en.wikipedia.org/wiki/Online_machine_learning
[5]: https://en.wikipedia.org/wiki/Unsupervised_learning
[6]: https://en.wikipedia.org/wiki/Semi-supervised_learning
[7]: https://en.wikipedia.org/wiki/Supervised_learning
[8]: https://en.wikipedia.org/wiki/Reinforcement_learning 
[9]: https://en.wikipedia.org/wiki/Q-learning
[10]: https://en.wikipedia.org/wiki/Rule-based_machine_learning
[11]: https://en.wikipedia.org/wiki/Temporal_difference_learning
[12]: https://en.wikipedia.org/wiki/State%E2%80%93action%E2%80%93reward%E2%80%93state%E2%80%93action
[13]: https://en.wikipedia.org/wiki/Markov_decision_process
[14]: https://en.wikipedia.org/wiki/One-shot_learning
[15]: https://en.wikipedia.org/wiki/Meta_learning_(computer_science)
[16]: https://www.aaai.org/Papers/IJCAI/2007/IJCAI07-416.pdf
[17]: http://ai.stanford.edu/~ang/papers/icml00-irl.pdf
[18]: https://www.aaai.org/Papers/AAAI/2008/AAAI08-227.pdf
[19]: https://en.wikipedia.org/wiki/Principle_of_maximum_entropy

[comment]: <Some Useful Sources>
[001]: https://machinelearningmastery.com/supervised-and-unsupervised-machine-learning-algorithms/
[002]: https://www.coursera.org/specializations/deep-learning#courses

[comment]: <Resources>
1. [Deep Reinforcement Learning: An Overview](https://arxiv.org/abs/1701.07274)
