#include "linesolver.h"

LineSolver::LineSolver() {}

bool LineSolver::isDotCovered (uint64_t test) {
    return (test & partialDot);
}

/* Tests whether the configuration would place a solid next to a known solid
   (which is not legal). First it ors a rightshifted and a leftshifted version
   of the block to be tested, adding the boundaries, to the testable e.g.

     test: 00111000
   solid:00000100

   lsh: 01110000
   rsh: 00011100
   test:00111000
   -------------
     or:  01111100

   This is then xored against the original testable to give the boundaries only:

   above result: 01111100
   test:         00111000
   ----------------------
   xor:          01000100

   Finally an and operation is performed against the solid. If the result is anything
   but zero, there is an abuttal:

   above result: 01000100
   solid:        00000100
   ----------------------
   and:          00000100
*/
bool LineSolver::isSolidAbutted (uint64_t test) {
    return ((((test << 1) | (test >> 1) | test) ^ test) & partialSolid);
}

/* Tests whether a solid is revealed when a block is moved right. "test" here is the
   block in its already moved configuration. An and operation is performed against the
     unmoved block. If this result is greater than the value of the test parameter it
     means a bit of higher significance has been unmasked, (i.e. a solid has been revealed).

     test: 00111000 (moved)
     solid:01100000

     lsh:  01110000 (unmoved)
     solid:01100000
     --------------
     and:  01100000 (> 00111000 -> a solid has been revealed)
*/
bool LineSolver::isSolidRevealed (uint64_t test) {
    return ((partialSolid & (test << 1)) > test);
}

/* Tests whether all predefined solids are covered by the suggested block. The
     suggested block may contain additional solids, which are not predefined. E.g.

     test: 01110110
     solid:01100010
     --------------
     and:  01100010 (== solid -> ok)
 */
bool LineSolver::isSolidMatch (uint64_t test) {
    return ((partialSolid & test) == partialSolid);
}

/* Creates an integer, which is a bit representation of a block, using its
     known position and size.

     First right shift a 1 to a position 1 step left of where the block should
     start, then subtract 1. Then right shift a 1 to where the block should end
     and subtract a one. Xor the two for a bit representation. E.g.

     position = 2 (Zero based indexing.)
     block_size = 3
     length = 8

     rsh_1 : 01000000
     -1    : 00111111

     rsh_1 : 00001000
     -1    : 00000111

     result_1 : 00111111
     result_2 : 00000111
     -------------------
     xor:       00111000
 */
uint64_t LineSolver::bitRepresentationOfBlock (uint64_t block_size, uint64_t position) {
    return ((((uint64_t)1 << (length - position)) - 1) ^ (((uint64_t)1 << (length - position - block_size)) - 1));
}

void LineSolver::printBitblock (uint64_t bitblock) {
    uint64_t i = (uint64_t)1 << (length - 1);
    do {
        if (bitblock & i) {
            cout << "#";
        }
        else {
            cout << "-";
        }
        i >>= 1;
    } while (i > 0);
    cout << endl;
}

void LineSolver::printResult () {
    uint64_t i = (uint64_t)1 << (length - 1);
    do {
        if (improvedSolid & i) {
            cout << "#";
        }
        else if (improvedDot & i) {
            cout << "+";
        }
        else {
            cout << "-";
        }
        i >>= 1;
    } while (i > 0);
    cout << endl;
}

// Tries to squeeze out every bit of information that can be squeezed out with the
// information already available. Will return "false" if additional information
// can not be found, otherwise "true".
bool LineSolver::solve (uint64_t block = 0, uint64_t position = 0, uint64_t parents = 0) {
    uint64_t temp = 0;
    // Calculate where to stop (because pushing the block any further
    // would mean that the remaining blocks wouldn't fit).
    // Each remaining block requires a minimum of their own size + 1.
    for (uint64_t i = block + 1; i < clue->size(); ++i) {
        temp += clue->at(i) + 1;
    }
    uint64_t rightmost_possible_position = (uint64_t)1 << temp;
    //int solid = 16744464;
    //int dot = 50364170;
    uint64_t bitblock = bitRepresentationOfBlock(clue->at(block), position);
    bool done = false;
    bool lastrun = bitblock & rightmost_possible_position;
    while (!done) {
        // If the block fits in the current position, we need to deal with it.
        if (!isDotCovered(bitblock) && !isSolidAbutted (bitblock)) {
            // If we're not on the last block, we move to the next one using recursion.
            if (block < clue->size() - 1) {
                if (!solve(block + 1, position + clue->at(block) + 1, parents | bitblock)) {
                    return false;
                }
            }
            // If we *are* on the last block, we check if it's a possible solution, which we add.
            else if (isSolidMatch(temp = parents | bitblock)) {
                improvedSolid &= temp;
                improvedDot |= temp;
                // It's impossible to squeeze out any additional information with this clue.
                if (improvedSolid == partialSolid && improvedDot == improvedDotMask - partialDot) {
                    return false;
                }
            }
        }
        // Move the block one notch forward.
        bitblock >>= 1;
        ++position;
        if (lastrun || isSolidRevealed(bitblock)) {
            done = true;
        }
        else if (bitblock & rightmost_possible_position) {
            lastrun = true;
        }
    }
    return true;
}

void LineSolver::solve(uint64_t l, uint64_t ps, uint64_t pd, vector<uint64_t> *c) {
    length = l;
    partialSolid = ps;
    partialDot = pd;
    clue = c;
    // The situation where the hint is "0" (i.e. line is all dots), is a special
    // situation. Fortunately it's very easy to deal with.
    if (c->at(0) == 0) {
        improvedSolid = 0;
        improvedDot = 0;
        improvedDotMask = ((uint64_t)1 << length) - 1;
    }
    // Normally we do this.
    else {
        improvedSolid = (uint64_t)-1;
        improvedDot = 0;
        improvedDotMask = ((uint64_t)1 << length) - 1;
        solve();
    }
}

uint64_t LineSolver::getSolid() {
    return improvedSolid;
}

/* The bits of the "improvedDot" variable are flipped because it's easier to build that way.
     This does not apply to the leading bits, though, so before it's returned we need to xor it
     against a number that is all 0's for the leading bits, and all 1's for the active bits.
 */
uint64_t LineSolver::getDot() {
    return (improvedDotMask ^ improvedDot);
}
