# -*- coding: utf-8 -*-

import random

class EcmaXp:
    __slots__ =['front','back','right','left','ceil','bottom']

    def __init__(self):
        self.front=self.back=self.right=self.left=self.ceil=self.bottom=0

    def dice(self):
        self.front = 3
        self.back = 4
        self.right = 2
        self.left = 5
        self.ceil = 1
        self.bottom = 6

    def roll(self, direction):
        if direction == 0:
            self.roll_front()
        elif direction == 1:
            self.roll_back()
        elif direction == 2:
            self.roll_left()
        else:
            self.roll_right()

    def roll_front(self):
        self.ceil, self.front, self.back, self.bottom =\
        (self.back, self.ceil, self.bottom, self.front)

    def roll_back(self):
        self.ceil, self.back, self.bottom, self.front =\
        (self.front, self.ceil, self.back, self.bottom)

    def roll_right(self):
        self.ceil, self.right, self.bottom, self.left =\
        (self.left, self.ceil, self.right, self.bottom)

    def roll_left(self):
        self.ceil, self.left, self.bottom, self.right =\
        (self.right, self.ceil, self.left, self.bottom)

class TestCase:
    __slots__ = ['dice','gene']

    def __init__(self,gene=None):
        dice = EcmaXp()
        dice.dice()

        if gene is None:
            gene = make_gene()

        for x in gene:
            dice.roll(x)

        self.dice = dice
        self.gene = gene

def make_gene():
    return [random.randint(0,3) for x in xrange(20)]

def crossing_gene(a,b):
    res = []
    for x in xrange(20):
        if random.randint(0,499) == 0:
            res.append(random.randint(0,3))
        else:
            res.append(random.choice([a.gene[x],b.gene[x]]))
    return res

def average(case):
    return reduce(lambda x,y:x+y.dice.ceil,case,0)/float(len(case))

def approx_equal(a, b, tol=.0000000001):
    return abs(a-b) < tol

def main():
    object_count = 1000
    case = [TestCase() for x in xrange(object_count)]
    generation = 0
    max_generation = 501
    while generation < max_generation:
        avg = average(case)
        print '%s: %f' % (generation, avg)

        if approx_equal(avg,5.9,0.01):
            break

        best_seed = sorted(case,key=lambda x:7-x.dice.ceil)[:object_count/4]

        case = []

        for x in xrange(object_count):
            case.append(TestCase(crossing_gene(*random.sample(best_seed,2))))

        generation += 1

    print '\n---reverse---\n'

    generation = 0
    while generation < max_generation:
        avg = average(case)
        print '%s: %f' % (generation, avg)

        if approx_equal(avg,1.1,0.01):
            break

        best_seed = sorted(case,key=lambda x:x.dice.ceil)[:object_count/4]

        case = []

        for x in xrange(object_count):
            case.append(TestCase(crossing_gene(*random.sample(best_seed,2))))

        generation += 1

if __name__ == '__main__':
    main()
