/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef Spine_IkConstraintTimeline_h
#define Spine_IkConstraintTimeline_h

#include <spine/CurveTimeline.h>

namespace Spine
{
    class IkConstraintTimeline : public CurveTimeline
    {
        SPINE_RTTI_DECL;
        
        virtual void apply(Skeleton& skeleton, float lastTime, float time, Vector<Event*>& events, float alpha, MixPose pose, MixDirection direction);
        
        virtual int getPropertyId();
        
//        public const int ENTRIES = 3;
//        private const int PREV_TIME = -3, PREV_MIX = -2, PREV_BEND_DIRECTION = -1;
//        private const int MIX = 1, BEND_DIRECTION = 2;
//        
//        internal int ikConstraintIndex;
//        internal float[] frames;
//        
//        public int IkConstraintIndex { return ikConstraintIndex; } set { ikConstraintIndex = inValue; }
//        public float[] Frames { return frames; } set { frames = inValue; } // time, mix, bendDirection, ...
//        
//        override public int PropertyId {
//            get { return ((int)TimelineType.IkConstraint << 24) + ikConstraintIndex; }
//        }
//        
//        public IkConstraintTimeline (int frameCount)
//        : base(frameCount) {
//            frames = new float[frameCount * ENTRIES];
//        }
//        
//        /// Sets the time, mix and bend direction of the specified keyframe.
//        public void SetFrame (int frameIndex, float time, float mix, int bendDirection) {
//            frameIndex *= ENTRIES;
//            frames[frameIndex] = time;
//            frames[frameIndex + MIX] = mix;
//            frames[frameIndex + BEND_DIRECTION] = bendDirection;
//        }
//        
//        override public void Apply (Skeleton skeleton, float lastTime, float time, Vector<Event> firedEvents, float alpha, MixPose pose, MixDirection direction) {
//            IkConstraint constraint = skeleton.ikConstraints.Items[ikConstraintIndex];
//            float[] frames = _frames;
//            if (time < frames[0]) {
//                switch (pose) {
//                    case MixPose_Setup:
//                        constraint.mix = constraint.data.mix;
//                        constraint.bendDirection = constraint.data.bendDirection;
//                        return;
//                    case MixPose_Current:
//                        constraint.mix += (constraint.data.mix - constraint.mix) * alpha;
//                        constraint.bendDirection = constraint.data.bendDirection;
//                        return;
//                }
//                return;
//            }
//            
//            if (time >= frames[frames.Length - ENTRIES]) { // Time is after last frame.
//                if (pose == MixPose_Setup) {
//                    constraint.mix = constraint.data.mix + (frames[frames.Length + PREV_MIX] - constraint.data.mix) * alpha;
//                    constraint.bendDirection = direction == MixDirection_Out ? constraint.data.bendDirection
//                    : (int)frames[frames.Length + PREV_BEND_DIRECTION];
//                } else {
//                    constraint.mix += (frames[frames.Length + PREV_MIX] - constraint.mix) * alpha;
//                    if (direction == MixDirection_In) constraint.bendDirection = (int)frames[frames.Length + PREV_BEND_DIRECTION];
//                }
//                return;
//            }
//            
//            // Interpolate between the previous frame and the current frame.
//            int frame = Animation.BinarySearch(frames, time, ENTRIES);
//            float mix = frames[frame + PREV_MIX];
//            float frameTime = frames[frame];
//            float percent = GetCurvePercent(frame / ENTRIES - 1, 1 - (time - frameTime) / (frames[frame + PREV_TIME] - frameTime));
//            
//            if (pose == MixPose_Setup) {
//                constraint.mix = constraint.data.mix + (mix + (frames[frame + MIX] - mix) * percent - constraint.data.mix) * alpha;
//                constraint.bendDirection = direction == MixDirection_Out ? constraint.data.bendDirection : (int)frames[frame + PREV_BEND_DIRECTION];
//            } else {
//                constraint.mix += (mix + (frames[frame + MIX] - mix) * percent - constraint.mix) * alpha;
//                if (direction == MixDirection_In) constraint.bendDirection = (int)frames[frame + PREV_BEND_DIRECTION];
//            }
//        }
    };
}

#endif /* Spine_IkConstraintTimeline_h */
