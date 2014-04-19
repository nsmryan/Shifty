module Shifty where

import qualified Prelude as P hiding (cycle, mod)
import Language.Copilot
import Copilot.Language
import Copilot.Library.Utils
import Copilot.Language.Operators.Integral
import Copilot.Language.Operators.Ord
import Copilot.Language.Operators.BitWise
import Copilot.Core.Type
import qualified Copilot.Core.Spec as C

import Control.Applicative


latch :: (Typed a) => a -> Stream Bool -> Stream a -> Stream a
latch initial sig vals =
  let lat = [initial, initial] ++ mux sig vals (drop 1 lat) in lat

upDown :: (Integral a, Typed a) => Stream a -> Stream a -> Stream a
upDown max slowDown =
  let is = (counter `div` slowDown)
      fullRange = is `mod` (2 * max)
      highLow = (fullRange `div` max) == 0
  in mux highLow fullRange (max - (fullRange `mod` max))

counter :: (Integral a, Typed a) => Stream a
counter = let val = [0] ++ (val + 1) in val

counterFrom :: (Integral a, Typed a) => a -> Stream a
counterFrom init = let val = [init] ++ (val + 1) in val

rolling :: Integer -> Stream Word32
rolling n = counter `mod` fromInteger n

everyN f n a =
  let as = [a] ++ mux ((counter `mod` n) == 0) (f as) as
      in as

pwmOutput pwm output pwmOutput =
  mux (pwm < pwmOutput) output 0

shiftOut = "shiftOut"

dutyCycleStream :: Stream Word16
dutyCycleStream = 20

dutyCycle :: Integer
dutyCycle = 20

rgb :: Spec
rgb = let
  outputClock p = (clk (period dutyCycle) (phase p))
  eachDutyCycle = latch (0 :: Word32) (outputClock 0)
  outputStream clock = (everyN (1+) dutyCycleStream (0 :: Word32))
  outputStreams = map (\ n -> counter `div` 500) [0..4]
  pwmCounts = map (P.const (upDown 20 (40 :: Stream Word32))) [0..4]
  pwmVals = counter `mod` (20 :: Stream Word32)
  outputVals = pwmOutput pwmVals <$> outputStreams <*> pwmCounts
  addRGB acc n = (acc .<<. (3 :: Stream Word32)) .|. (n .&. (0x7 :: Stream Word32))
  output = foldl1 addRGB outputVals
  in
    trigger shiftOut true [arg output]



