module Main where

import qualified Prelude as P
import Copilot.Language.Prelude

import Copilot.Compile.C99
import Copilot.Language.Reify
import Copilot.Language

import System.Directory
import System.Process

import Shifty


main :: IO ()
main = do
  spec <- reify rgb
  compile defaultParams spec
