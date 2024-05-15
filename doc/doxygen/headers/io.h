// ------------------------------------------------------------------------
//
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright (C) 2006 - 2020 by the deal.II authors
//
// This file is part of the deal.II library.
//
// Part of the source code is dual licensed under Apache-2.0 WITH
// LLVM-exception OR LGPL-2.1-or-later. Detailed license information
// governing the source code and code contributions can be found in
// LICENSE.md and CONTRIBUTING.md at the top level directory of deal.II.
//
// ------------------------------------------------------------------------


/**
 * @defgroup IO Input/Output
 *
 * This module collects the classes used for reading and writing meshes and
 * data. There are two sub-modules for each of these operations.
 */

/**
 * @defgroup input Input
 *
 * deal.II can read meshes in a number of different formats. However, all of
 * them are constrained to so-called "coarse meshes", i.e. meshes that have no
 * refinement hierarchy and in particular no hanging nodes. The GridIn class
 * describes in detail what formats are supported.
 *
 * In addition, deal.II can read an intermediate graphics format using the
 * DataOutReader. This format is used as an intermediate step between data
 * associated with a simulation and is written by the DataOutBase class (or
 * through the more derived classes described in the \ref output module). The
 * DataOutReader class reads this data back in, and it can then be converted
 * to any of a number of data formats supported by visualization programs.
 *
 * Finally, the ParameterHandler and MultipleParameterLoop classes (and the
 * associated Patterns namespace) are used to deal with parameter files
 * describing run-time parameters to a program that one doesn't want to
 * hard-code within the program source.
 *
 *
 * <h3>The PathSearch class</h3>
 *
 * The PathSearch class is a helper class in input handling. It is
 * used to find a file in a list of directories, in much the same way
 * as unix systems find executables among the directories listed in
 * the <code>PATH</code> environment variable.
 *
 * @ingroup IO
 */

/**
 * @defgroup output Graphical output
 *
 * deal.II generates three types of output: it can write triangulations/meshes
 * in formats understood by several mesh readers (including those of deal.II
 * itself), and it can create output used for visualization of data. Finally,
 * it can output matrices in a graphical format.
 *
 *
 * <h3>Visualization of data</h3>
 *
 * deal.II supports, through the DataOutBase class, a large number of popular
 * visualization formats, such as those used by the OpenDX, gmv, or gnuplot
 * programs. A complete list of supported formats is listed in the
 * documentation of the DataOutBase class.
 *
 * The DataOutBase class is only responsible for actually writing some
 * intermediate format in a number of different visualization formats. This
 * intermediate format is generated by classes derived, directly or
 * indirectly, from DataOutBase. For example, the DataOut class is most often
 * used to generate this intermediate format from a triangulation, a
 * DoFHandler object (that associates a particular finite element class with
 * the triangulation), and one or more data vectors. The DataOut class creates
 * intermediate data from each cell, which is subsequently written by the
 * DataOutBase class in some final format. Almost all example programs,
 * starting with step-3, make use of this method of generating output.
 *
 * The DataOutFaces class is another way to create intermediate format from
 * simulation data. However, instead of creating visualization data from each
 * cell of the triangulation, it only creates information for all faces of
 * cells that are located on the surface (though the class has a way to
 * override the choice for which faces output should be generated). While this
 * may not be particularly interesting in 2d (the faces would only be line
 * segments) it is often helpful in 3d if what one really wants to know is the
 * shape of the domain or the value of one variable on the surface. Using the
 * DataOutFaces class then saves the effort of generating and storing data for
 * all interior cells, which can be very expensive for large 3d simulations.
 *
 * A third class, the DataOutRotation class, allows to take a two-dimensional
 * simulation and generate three-dimensional data from it by rotating the
 * two-dimensional domain around a given axis. This is mostly useful for the
 * visualization of simulations that use the rotational symmetry of, for
 * example, a cylinder.
 *
 * Finally, the DataOutStack class allows to visualize data from time
 * dependent simulations in the space-time domain: it collects the results
 * from each time step and at the end outputs all of this information at once
 * as a space-time file.
 *
 *
 * <h3>Grid output</h3>
 *
 * Meshes, without any data vectors associated with it, can be written in a
 * number of formats as well. This is done through the GridOut class, and the
 * documentation of that class lists the supported formats.
 *
 * Several of the tutorial programs, notably step-1, step-6, step-9, step-10,
 * and step-14 demonstrate the use of the GridOut class.
 *
 *
 * <h3>Matrix output</h3>
 *
 * Through the MatrixOut class, deal.II can also give a graphical
 * visualization of matrices, in the form of color or skyline plots. The
 * MatrixOut class uses the DataOutBase for output. Therefore, matrices can be
 * visualized in all formats supported by the latter class.
 *
 * @ingroup IO
 */

/**
 * @defgroup textoutput Textual output
 *
 * In addition to classes that provide graphical output formats (see the @ref
 * output module), deal.II has a number of classes that facilitate textual
 * output in a number of ways. They are collected in this module. See the
 * documentation of these classes for more details.
 *
 * @ingroup IO
 */
