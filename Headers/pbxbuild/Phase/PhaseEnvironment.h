/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_Phase_PhaseEnvironment_h
#define __pbxbuild_Phase_PhaseEnvironment_h

#include <pbxbuild/Base.h>
#include <pbxbuild/BuildEnvironment.h>
#include <pbxbuild/BuildContext.h>
#include <pbxbuild/TargetEnvironment.h>

namespace pbxbuild {

class TypeResolvedFile;

namespace Phase {

class PhaseEnvironment {
private:
    BuildEnvironment                 _buildEnvironment;
    BuildContext                     _buildContext;
    pbxproj::PBX::Target::shared_ptr _target;
    TargetEnvironment                _targetEnvironment;

public:
    PhaseEnvironment(BuildEnvironment const &buildEnvironment, BuildContext const &buildContext, pbxproj::PBX::Target::shared_ptr const &target, TargetEnvironment const &targetEnvironment);
    ~PhaseEnvironment();

public:
    BuildEnvironment const &buildEnvironment() const
    { return _buildEnvironment; }
    BuildContext const &buildContext() const
    { return _buildContext; }
    pbxproj::PBX::Target::shared_ptr const &target() const
    { return _target; }
    TargetEnvironment const &targetEnvironment() const
    { return _targetEnvironment; }

public:
    std::unique_ptr<pbxbuild::TypeResolvedFile> resolveReferenceProxy(pbxproj::PBX::ReferenceProxy::shared_ptr const &referenceProxy, pbxsetting::Environment const &environment) const;
    std::unique_ptr<pbxbuild::TypeResolvedFile> resolveFileReference(pbxproj::PBX::FileReference::shared_ptr const &fileReference, pbxsetting::Environment const &environment) const;

public:
    static pbxsetting::Level
    VariantLevel(std::string const &variant);
    static pbxsetting::Level
    ArchitectureLevel(std::string const &arch);
};

}
}

#endif // !__pbxbuild_Phase_PhaseEnvironment_h
