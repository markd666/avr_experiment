load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# To pull the EmbeddedSystemsBuildScripts
http_archive(
    name = "EmbeddedSystemsBuildScripts",
    strip_prefix = "EmbeddedSystemsBuildScripts-master",
    urls = ["https://github.com/markd666/EmbeddedSystemsBuildScripts/archive/master.tar.gz"],
)

#local_repository(
#    name = "EmbeddedSystemsBuildScripts",
#    path = "/home/mark/code/JointSoftware/discoveryZone/EmbeddedSystemsBuildScripts",
#)

load("@EmbeddedSystemsBuildScripts//AvrToolchain:avr.bzl", "avr_toolchain")

avr_toolchain()
